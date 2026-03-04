#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int n,m;
vector<pair<int,int>> nxt[MAXN];
bitset<MAXN> vis;
long long ans;

void init(){
    ans = 0;
    for(int i=0; i<n; i++){
        nxt[i].clear();
    }
    vis.reset();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin>>n>>m){
        init();
        for(int i=0; i<m; i++){
            int a,b,c;
            cin>>a>>b>>c;
            nxt[a].push_back({b,c});
            nxt[b].push_back({a,c});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0,0});
        int cnt = 0;
        while(pq.size()){
            auto [w,u] = pq.top();
            pq.pop();
            if(vis[u]) continue;

            vis[u] = 1;
            ans += w;
            cnt++;

            for(auto &[v,w]: nxt[u]){
                pq.push({w,v});
            }
        }
        
        // cout<<cnt<<'\n';
        if(cnt == n) cout<<ans<<'\n';
        else cout<<-1<<'\n';
    }
}