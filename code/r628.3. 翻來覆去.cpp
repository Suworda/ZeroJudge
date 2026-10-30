
#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;

struct BIT{
    int n;
    vector<int> b;

    BIT(int _n): n(_n), b(n+1) {}

    void upd(int x, int v){
        while(x <= n){
            b[x] += v;
            x += x & -x;
        }
    }

    int query(int x){
        int rst = 0;
        while(x){
            rst += b[x];
            x -= x & -x;
        }
        return rst;
    }

    int query(int l, int r){
        return query(r) - query(l-1);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    BIT valid_cnt(n+1);
    vector<int> v(n+1), p(n+1);
    for(int i=n; i>=1; i--){
        cin>>v[i];
        p[v[i]] = i;
        valid_cnt.upd(i, 1);
    }

    int last = n+1;
    int ans = 0;
    for(int i=1; i<=n; i++){
        int cut = p[i];
        valid_cnt.upd(cut, -1);
        ans += max(valid_cnt.query(last, cut), valid_cnt.query(cut, last));
        last = cut;
    }

    cout << n + ans << '\n';




    

}
