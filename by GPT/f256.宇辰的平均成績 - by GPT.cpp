// by GPT-6 Astra Ultra

// ZeroJudge f256: GCC C++17 / Linux x86-64 with AVX2.
// Input assumptions: 0 <= grade <= 100, 1 <= credit <= 4;
// <= 5,000,000 records; canonical decimal (NO leading zeroes);
// exactly one space or tab between fields, one record per line,
// no leading/trailing whitespace. LF/CRLF and missing final newline work.
// Specialized for speed: this is NOT a general integer parser.

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cerrno>
#include <immintrin.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

struct Kernel {
    __m256i total_a, total_b;

    Kernel() : total_a(_mm256_setzero_si256()),
               total_b(_mm256_setzero_si256()) {}

    // Each block owns 32 possible separator positions.
    // Caller supplies two readable bytes before p and one after the blocks.
    void scan(const char* p, size_t blocks) {
        const auto zero = _mm256_setzero_si256();
        const auto nibble = _mm256_set1_epi8(15);
        const auto sep_bits = _mm256_set1_epi8(0x16);
        const auto ones = _mm256_set1_epi16(1);
        const auto lut = _mm256_setr_epi8(
             52,-38,-28,-18,-8,2,12,22,32,42,-48,-48,-48,-48,-48,-48,
             52,-38,-28,-18,-8,2,12,22,32,42,-48,-48,-48,-48,-48,-48);

        while (blocks) {
            size_t count = blocks > 48 ? 48 : blocks;
            blocks -= count;
            auto a = zero, b = zero;
            const char* stop = p + count * 32;
            do {
                auto s = _mm256_loadu_si256((const __m256i*)p);
                auto u = _mm256_loadu_si256((const __m256i*)(p - 1));
                auto t = _mm256_loadu_si256((const __m256i*)(p - 2));
                auto c = _mm256_loadu_si256((const __m256i*)(p + 1));

                auto sep = _mm256_cmpeq_epi8(
                    _mm256_and_si256(s, sep_bits), zero);
                auto grade = _mm256_add_epi8(u, _mm256_shuffle_epi8(lut, t));
                auto credit = _mm256_and_si256(
                    _mm256_and_si256(c, nibble), sep);

                a = _mm256_add_epi16(a, _mm256_maddubs_epi16(grade, credit));
                b = _mm256_add_epi8(b, credit);
                p += 32;
            } while (p != stop);

            // A 16-bit lane <= 48*400=19200, an 8-bit lane <= 48*4=192.
            total_a = _mm256_add_epi32(total_a, _mm256_madd_epi16(a, ones));
            total_b = _mm256_add_epi64(total_b, _mm256_sad_epu8(b, zero));
        }
    }

    void sums(uint64_t& a, uint64_t& b) const {
        alignas(32) uint32_t as[8];
        alignas(32) uint64_t bs[4];
        _mm256_store_si256((__m256i*)as, total_a);
        _mm256_store_si256((__m256i*)bs, total_b);
        a = b = 0;
        for (auto v : as) a += v;
        for (auto v : bs) b += v;
    }

    bool cannot_pass(size_t remaining) const {
        uint64_t a, b;
        sums(a, b);
        // Only grades >=61 make a positive contribution to A-60*B.
        // Such separators are >=5 bytes apart, and each contributes <=160.
        // Thus remaining positive contribution <= 32*remaining+160.
        return 60 * b > a + 32 * uint64_t(remaining) + 160;
    }

    void finish() const {
        uint64_t a, b;
        sums(a, b);
        if (!b) return;
        unsigned avg = unsigned(a / b);
        if (avg < 60) puts("YEEEEEE!!!");
        else printf("Oh wow! You pass it!\n%u\n", avg);
    }
};

static bool mapped(Kernel& k, const char* p, size_t n) {
    // Copy boundary blocks into padded storage; never overread the mapping.
    alignas(64) char edge[128];
    memset(edge, '\n', sizeof edge);
    size_t i = 0;
    if (n >= 33) {
        memcpy(edge + 32, p, 33);
        k.scan(edge + 32, 1);
        i = 32;
        size_t blocks = (n - i - 1) / 32;
        constexpr size_t check_blocks = (1u << 18) / 32;
        while (blocks) {
            size_t count = blocks > check_blocks ? check_blocks : blocks;
            k.scan(p + i, count);
            i += count * 32;
            blocks -= count;
            if (k.cannot_pass(n - i)) return true;
        }
        memset(edge, '\n', sizeof edge);
        memcpy(edge + 30, p + i - 2, 2);
    }
    memcpy(edge + 32, p + i, n - i);
    k.scan(edge + 32, (n - i + 31) / 32);
    return false;
}

static bool streamed(Kernel& k) {
    constexpr size_t S = 1u << 16;
    alignas(64) static char buf[S + 128];
    char* data = buf + 32;
    memset(buf, '\n', 32);
    size_t carry = 0;
    while (true) {
        ssize_t r;
        do {
            r = read(0, data + carry, S - carry);
        } while (r < 0 && errno == EINTR);
        if (r < 0) return false;
        size_t len = carry + size_t(r);
        if (!r) {
            memset(data + len, '\n', 33);
            k.scan(data, (len + 31) / 32);
            return true;
        }
        size_t blocks = len > 32 ? (len - 1) / 32 : 0;
        k.scan(data, blocks);
        size_t used = blocks * 32;
        carry = len - used;
        memmove(data - 2, data + used - 2, carry + 2);
    }
}

int main() {
    Kernel k;
    struct stat st;
    if (fstat(0, &st) == 0 && S_ISREG(st.st_mode) && st.st_size > 0) {
        size_t n = size_t(st.st_size);
        void* m = mmap(nullptr, n, PROT_READ, MAP_PRIVATE | MAP_POPULATE, 0, 0);
        if (m != MAP_FAILED) {
            bool early_failure = mapped(k, static_cast<const char*>(m), n);
            munmap(m, n);
            if (early_failure) puts("YEEEEEE!!!");
            else k.finish();
            return 0;
        }
    }
    // Pipe input, or mmap unavailable.
    if (!streamed(k)) return 1;
    k.finish();
}
