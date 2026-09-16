#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int N = 150005;
int n,k;
int a[N];
int dp[N][21];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];

    int ans = 0;
    for(int i=1; i<=n; i++){
        dp[i][0] = max(0LL, dp[i-1][0] + a[i]);
        ans = max(ans, dp[i][0]);
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            dp[i][j] = max(dp[i-1][j] + a[i], dp[i-1][j-1]);
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << '\n';
    
}