#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX_V = 200005;

void sol(){
    int n;
    cin>>n;
    vector<int> cnt(MAX_V+5,0);
    vector<int> dp(MAX_V+5,0);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        cnt[x]++;
    }

    int ans = 0;
    for(int i=1; i<=MAX_V; i++){
        dp[i] += cnt[i];
        ans = max(ans, dp[i]);
        for(int j=i+i; j<=MAX_V; j+=i){
            dp[j] = max(dp[j], dp[i]);
        }
    }

    cout << n - ans << '\n';


}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--) sol();

}