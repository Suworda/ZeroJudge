#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,k;
int a[1000005];
int dp[1000005][21];
int apr[100005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];

    int ans = 0;
    for(int i=1; i<=k; i++){
        int l = 1;
        for(int r=1; r<=n; r++){
            while(apr[a[r]] == i){
                apr[a[l]] = 0;
                l++;
            }
            apr[a[r]] = i;
    
            dp[r][i] = max(dp[r-1][i], (r - l + 1) + dp[l-1][i-1]);
            ans = max(ans, dp[r][i]);
        }
    }

    cout << ans << '\n';

}