#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int a,b,w;

    bool operator< (const Edge &other) const{
        return w < other.w;
    }
};

int n,m;
Edge edge[200005];
int parent[100005];

int find_pa(int x){
    if(parent[x] == x) return x;
    return parent[x] = find_pa(parent[x]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin>>n>>m){
        iota(parent, parent+n, 0);
        
        for(int i=0; i<m; i++){
            cin >> edge[i].a >> edge[i].b >> edge[i].w;
            
        }
        
        sort(edge, edge+m);
        
        long long ans=0;
        int cnt = 1;
        for(int i=0; i<m; i++){
            auto [v,u,w] = edge[i];
            int pv = find_pa(v);
            int pu = find_pa(u);
            if(pv != pu){
                cnt++;
                ans += w;
                // cout<<i<<' ';
                parent[pv] = pu;
            }
        }

        if(cnt == n) cout<<ans<<'\n';
        else cout<<-1<<'\n';

    }

}