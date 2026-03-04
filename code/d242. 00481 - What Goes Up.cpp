#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
vector<int> parent;
vector<int> v;
vector<int> dp_idx;


int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int x;
    while(cin>>x){
        v.push_back(x);
    }

    parent.resize(v.size());

    dp.push_back(v[0]);
    dp_idx.push_back(0);
    parent[0] = -1;

    for(int i=1; i<v.size(); i++){
        if(v[i] > dp.back()){
            dp.push_back(v[i]);
            parent[i] = dp_idx.back();
            dp_idx.push_back(i);

        }else{
            auto it = lower_bound(dp.begin(), dp.end(), v[i]);
            int idx = it - dp.begin();
            if(idx-1 == -1) parent[i] = -1;
            else parent[i] = dp_idx[idx-1];
            dp[idx] = v[i];
            dp_idx[idx] = i;

        }

    }

    // for(int i=0; i<dp.size(); i++){
    //     cout<<dp_idx[i]<<' '<<dp[i]<<'\n';
    // }
    // cout<<'\n';

    // for(int x: parent) cout<<x<<' ';
    // cout<<'\n';

    cout<<dp.size()<<'\n';
    cout<<"-\n";

    vector<int> ans;

    int cur = dp_idx.back();
    while(cur != -1){
        ans.push_back(v[cur]);
        cur = parent[cur];
    }
    reverse(ans.begin(), ans.end());

    for(int &x: ans){
        cout<<x<<'\n';
    }
    

}