#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int l,r,w,t[n+5];
    int d[n+5]={};
    for(int i=0; i<m; i++){
        cin>>l>>r>>w;
        d[l]+=w;
        d[r+1]-=w;
    }

    int cur=0;
    vector<int> v;
    for(int i=1; i<=n; i++){
        cur+=d[i];
        if(cur) v.push_back(cur);
    }
    sort(v.begin(), v.end(), greater<int>());

    for(int i=0; i<n; i++){
        cin>>t[i];
    }
    sort(t,t+n);

    long long ans=0;
    for(int i=0; i<v.size(); i++){
        //cout<<v[i]<<' ';
        ans+=v[i]*t[i];
    }

    cout<<ans<<'\n';

}
