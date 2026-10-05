#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Query{
    int l, r, id;

    bool operator< (const Query &b) const{
        return r < b.r;
    }
};

int n,Q;
int a[400005];
int b[400005];
int ans[400005];
int last[400005];
vector<Query> q;

void upd(int k, int v){
    while(k <= n){
        b[k] += v;
        k += k & (-k);
    }
}

ll query(int k){
    ll rst = 0;
    while(k){
        rst += b[k];
        k -= k & (-k);
    }

    return rst;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    cin>>Q;
    
    for(int i=0; i<Q; i++){
        int l, r;
        cin>>l>>r;
        q.push_back({l,r,i});
    }

    sort(q.begin(), q.end());

    int q_id = 0;

    for(int i=1; i<=n; i++){
        if(last[a[i]]) upd(last[a[i]], -1);
        upd(i, +1);
        while(q_id < Q && q[q_id].r == i){
            auto [l,r,id] = q[q_id];

            ans[id] = query(n) - query(l-1);

            q_id++;
        }

        last[a[i]] = i;
    }

    for(int i=0; i<Q; i++){
        cout << ans[i] << '\n';
    }
}