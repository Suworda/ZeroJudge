#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k,n,m,f;
    while(cin>>k>>n>>m>>f){
        vector<int> a(k);
        for(int &x: a) cin>>x;

        sort(a.begin(), a.end(), greater<int>());

        int ans = 0;
        int id = 0;
        for(int i=1; i<=n; i+=f){
            if(id >= k) break;
            ans += max(i-m, 0LL) * a[id++];
        }

        cout << ans << '\n';
    }

}