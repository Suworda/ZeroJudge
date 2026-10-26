#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Graph{
    int n = 128;
    vector<set<int>> nxt, pre;
    vector<int> ori_outdeg;
    string ans;

    Graph(string s): nxt(128), pre(128), ori_outdeg(128) {
        for(int i=0; i<128; i++) ori_outdeg[i] = -1;
        for(char c: s) ori_outdeg[c] = 0;
    }

    void add_edge(char a, char b){
        if(nxt[a].count(b)) return;
        pre[b].insert(a);
        nxt[a].insert(b);
        ori_outdeg[a]++;
    }

    void topo_sort(){
        auto outdeg = ori_outdeg;
        queue<int> q;
        for(int i=0; i<128; i++){
            if(outdeg[i] == 0){
                q.push(i);
            }
        }

        while(q.size()){
            int u = q.front(); q.pop();
            ans.push_back(char(u));
            for(int v: pre[u]){
                outdeg[v]--;
                if(outdeg[v] == 0) q.push(v);
            }
        }
    }
};

string t[100005];
void dfs(int id, int l, int r, Graph &g){
    if(id >= 10) return;

    int nl = l;
    for(int i=l+1; i<=r; i++){
        if(t[i][id] != t[i-1][id]){
            g.add_edge(t[i-1][id], t[i][id]);
            if(nl != -1){
                dfs(id+1, nl, i-1, g);
            }
            nl = i;
        }
        if(i == r && nl != r){
            dfs(id+1, nl, r, g);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    bitset<128> vis;
    for(int i=0; i<n; i++){
        cin>>t[i];
        for(char c: t[i]) vis[c] = 1;
        t[i].resize(10, '*');
    }

    string s;
    for(int i=0; i<128; i++) if(vis[i]) s += char(i);

    Graph g(s);

    dfs(0, 0, n-1, g);

    g.topo_sort();

    auto ans = g.ans;
    reverse(ans.begin(), ans.end());
    for(char c: ans) if(c != '*') cout << c;
    cout << '\n';

}