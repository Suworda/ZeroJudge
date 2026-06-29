#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int N;
int p1[35];
int p2[35];
int ans;

void f(int n, int t){
    if(n == 0) return;
    cout<<n<<' '<<p1[n]<<' '<<t<<'\n';

    if(p1[n] != t){
        f(n-1, 6-p1[n]-t);
        cout<<"move: "<<n<<' '<<p1[n]<<' '<<t<<'\n';
        p1[n] = t;
        ans++;
    }
    f(n-1, p2[n-1]);
    
}

void sol(){
    ans = 0;
    for(int i=1; i<=N; i++) cin>>p1[i];
    for(int i=1; i<=N; i++) cin>>p2[i];

    f(N,p2[N]);

    cout<<ans<<'\n';

}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    while(cin>>N && N) sol();
}