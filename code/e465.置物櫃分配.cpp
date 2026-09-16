#include <iostream>
#include <bitset>
using namespace std;
int m,s,n,a;
bitset<100005> dp;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>s>>n;
    int x = m;
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        cin>>a;
        x -= a;
        for(int j=x; j>=0; j--){
            if(j - a >= 0 && dp[j-a]) dp[j] = 1;
        }
    }
    for(int i=max(0,s-x); i<=m; i++){
        if(dp[i]){
            cout << i << '\n';
            return 0;
        }
    }
}