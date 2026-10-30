#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const ll INF = 2e15;

struct Graph{
    int n;
    vector<pair<int,int>> nxt;
    vector<int> vis;
    vector<int> indeg;
    int mx_negtive_num = -INF;
    bool is_all_negtive = 1;
    int ans = -INF;

    Graph(int _n): n(_n), indeg(n+1), vis(n+1), nxt(n+1) {}

    void add_edge(int a, int b, int c){
        if(c < 0) mx_negtive_num = max(mx_negtive_num, c);
        else is_all_negtive = 0;
        nxt[a] = {b,c};
        indeg[b] = 1;
    }

    vector<vector<int>> find_circle(){
        vector<vector<int>> circles;
        for(int u=1; u<=n; u++){
            vector<int> circle;
            while(!vis[u]){
                auto [v,w] = nxt[u];
                vis[u] = 1;
                circle.push_back(w);
                u = v;
            }
            if(!circle.size()) continue;
            circles.push_back(circle);
        }

        return circles;
    }

    void check_case1(){
        for(int i=1; i<=n; i++){
            if(indeg[i] == 0){
                int u = i;
                int cur = 0;
                vis[u] = 1;
                while(nxt[u].first){
                    auto [v,w] = nxt[u];
                    cur = max(0LL, cur+w);
                    ans = max(ans, cur);
                    u = v;
                    vis[v] = 1;
                }
            }
        }
    }

    void check_case2(){
        auto circles = find_circle();
        for(auto circle: circles){
            vector<int> sum{0};
            int last = 0;
            for(int x: circle){
                sum.push_back(last + x);
                last += x;
            }
            for(int x: circle){
                sum.push_back(last + x);
                last += x;
            }

            int k = circle.size();
            int sz = sum.size();
            vector<int> dq(sz*2+5);
            int head = sz+2;
            int tail = sz+1;

            for(int i=0; i<sz; i++){
                // remove not valid
                while(head <= tail && dq[head] < i-k) head++;

                // remove not useful
                while(head <= tail && sum[i] <= sum[dq[tail]]){
                    tail--;
                }

                // upd
                ans = max(ans, sum[i] - sum[dq[head]]);

                //add
                dq[++tail] = i;
            }

        }
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    
    Graph g(n);

    while(m--){
        int a, b, c;
        cin>>a>>b>>c;
        g.add_edge(a, b, c);
    }

    if(g.is_all_negtive){
        cout << g.mx_negtive_num << '\n';
        return 0;
    }

    g.check_case1();

    g.check_case2();

    cout << g.ans << '\n';


}