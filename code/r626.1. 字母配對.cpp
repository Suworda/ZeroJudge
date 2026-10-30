#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
pair<char, int> a[8][15];
bitset<5000005> vis;
int dp[5000005];

int change(const array<int,6> &v){
    int rst = 0;
    int x = 1;
    for(int i=0; i<6; i++){
        rst += v[i] * x;
        x *= 13;
    }
    return rst;
}

int f(array<int,6> v){
    int id = change(v);
    if(vis[id]) return dp[id];

    int rst = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            auto [c1,x1] = a[i][v[i]];
            auto [c2,x2] = a[j][v[j]];
            if(v[i] > 0 && v[j] > 0 && c1 == c2){
                v[i]--; v[j]--;
                rst = max(rst, f(v) + x1 + x2);
                v[i]++; v[j]++;
            }
        }
    }
    vis[id] = 1;
    return dp[id] = rst;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    array<int,6> v = {};
    for(int i=0; i<n; i++){
        int m;
        cin>>m;
        v[i] = m;
        for(int j=1; j<=m; j++){
            cin >> a[i][m-j+1].first >> a[i][m-j+1].second;
        }
    }

    cout << f(v) << '\n';
}