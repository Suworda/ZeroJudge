#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll p;
    cin>>p;
    vector<int> ans;
    while(p){
        bool flag = 0;
        for(int i=9; i>=2; i--){
            if(p%i == 0){
                p /= i;
                ans.push_back(i);
                flag = 1;
                break;
            }
        }

        if(p == 1) break;

        if(!flag && p > 1){
            cout << -1 << '\n';
            return 0;
        }
    }

    sort(ans.begin(), ans.end());
    for(int x: ans) cout << x << ' ';

}