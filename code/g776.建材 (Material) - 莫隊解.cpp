#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Query{
    int l, r, id;
};

int K;

void add(vector<int> &cnt, int &rst, int x){
    if(cnt[x] == 0) rst++;
    cnt[x]++;
}

void rm(vector<int> &cnt, int &rst, int x){
    if(cnt[x] == 1) rst--;
    cnt[x]--;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    K = sqrt(n);
    vector<int> a(n+1), cnt(n+1);
    for(int i=0; i<n; i++) cin>>a[i];

    int Q;
    cin>>Q;
    vector<vector<Query>> q(K+2);
    vector<int> ans(Q+1);

    for(int i=0; i<Q; i++){
        int l, r;
        cin>>l>>r;
        l--;
        r--;
        q[l/K].push_back({l,r,i});
    }


    for(int i=0; i<q.size(); i++){
        if(i & 1 == 0){
            sort(q[i].begin(), q[i].end(), [](Query A, Query B){
                return A.r < B.r;
            });
        }
        else{
            sort(q[i].begin(), q[i].end(), [](Query A, Query B){
                return A.r > B.r;
            });
        }
    }

    int l = 0, r = 0;
    int rst = 1;
    cnt[a[l]]++;

    for(int i=0; i<q.size(); i++){
        for(int j=0; j<q[i].size(); j++){
            auto [L,R,id] = q[i][j];
            while(L < l) add(cnt, rst, a[--l]);
            while(r < R) add(cnt, rst, a[++r]);

            while(l < L) rm(cnt, rst, a[l++]);
            while(R < r) rm(cnt, rst, a[r--]);
            
            ans[id] = rst;
        }
    }

    for(int i=0; i<Q; i++) cout << ans[i] << '\n';
}