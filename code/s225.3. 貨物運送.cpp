#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define ll long long
const int INF = 2e9;

int n,k;
int dp[2005][2005];
int cost[2005][2005];
int a[2005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    for(int i=1; i<=k; i++) cin>>a[i];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>cost[i][j];
        }
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            dp[i][j] = INF;
        }
    }

    a[0] = 1;
    dp[0][0] = 0;
    dp[0][1] = cost[a[0]][a[1]];
    dp[1][0] = cost[a[1]][a[0]];

    for(int i=1; i<=k-1; i++){
        for(int j=0; j<i; j++){
            int x = i;
            dp[x+1][j] = min(dp[x+1][j], dp[i][j] + cost[a[i]][a[x+1]]);
            dp[i][x+1] = min(dp[i][x+1], dp[i][j] + cost[a[j]][a[x+1]]);
            swap(i,j);
            dp[x+1][j] = min(dp[x+1][j], dp[i][j] + cost[a[i]][a[x+1]]);
            dp[i][x+1] = min(dp[i][x+1], dp[i][j] + cost[a[j]][a[x+1]]);
            swap(i,j);
            
        }
    }

    int ans = INF;
    for(int i=0; i<=k-1; i++){
        ans = min(ans, dp[i][k] + cost[a[i]][n] + cost[a[k]][n]);
        ans = min(ans, dp[k][i] + cost[a[i]][n] + cost[a[k]][n]);
    }

    cout << ans << '\n';

}