#include <bits/stdc++.h>
using namespace std;

struct File{
    int a, b, c, d, id;
};

bool cmp_a(const File &x, const File &y){
    return x.a < y.a;
}

bool cmp_b(const File &x, const File &y){
    return x.b < y.b;
}

bool cmp_c(const File &x, const File &y){
    return x.c < y.c;
}

bool cmp_d(const File &x, const File &y){
    return x.d < y.d;
}

bool cmp_a2(const File &x, const File &y){
    return x.a > y.a;
}

bool cmp_b2(const File &x, const File &y){
    return x.b > y.b;
}

bool cmp_c2(const File &x, const File &y){
    return x.c > y.c;
}

bool cmp_d2(const File &x, const File &y){
    return x.d > y.d;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    vector<File> v;

    for(int i=0; i<n; i++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        v.push_back({a,b,c,d,i});
    }

    vector<int> p[5];

    vector<pair<int,int>> p_ord;

    vector<int> v_k;

    for(int i=0; i<k; i++){
        int x;
        cin>>x;
        v_k.push_back(x);
        p[x].push_back(i);
    }

    for(int i=1; i<=4; i++){
        if(p[i].size()) p_ord.push_back({p[i].back(), i});
    }

    sort(p_ord.begin(), p_ord.end());

    for(auto [id, x]: p_ord){
        if(x == 1){
            int cnt = 0;
            for(int i = id; i>=0; i--){
                if(v_k[i] != x) break;
                cnt++;
            }
            if(cnt%2 == 1) stable_sort(v.begin(), v.end(), cmp_a);
            else stable_sort(v.begin(), v.end(), cmp_a2);
            
        }
        else if(x == 2){
            int cnt = 0;
            for(int i = id; i>=0; i--){
                if(v_k[i] != x) break;
                cnt++;
            }
            if(cnt%2 == 1) stable_sort(v.begin(), v.end(), cmp_b);
            else stable_sort(v.begin(), v.end(), cmp_b2);
            
        }
        else if(x == 3){
            int cnt = 0;
            for(int i = id; i>=0; i--){
                if(v_k[i] != x) break;
                cnt++;
            }
            if(cnt%2 == 1) stable_sort(v.begin(), v.end(), cmp_c);
            else stable_sort(v.begin(), v.end(), cmp_c2);
            
        }
        else{
            int cnt = 0;
            for(int i = id; i>=0; i--){
                if(v_k[i] != x) break;
                cnt++;
            }
            if(cnt%2 == 1) stable_sort(v.begin(), v.end(), cmp_d);
            else stable_sort(v.begin(), v.end(), cmp_d2);
            
        }
    }

    for(auto ans: v){
        cout << ans.a << ' ' << ans.b << ' ' << ans.c << ' ' << ans.d << '\n';
    }
}
