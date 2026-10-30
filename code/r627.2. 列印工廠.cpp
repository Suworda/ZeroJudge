#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Seg{
    int s, d, t;
};

int n;
int ans = 0;
vector<Seg> v;

bool valid(vector<Seg> &v, int mid){
    int last = -2e9;
    for(int i=0; i<n; i++){
        if(max(last + mid, v[i].s) + v[i].t > v[i].d) return false;
        last = max(last + mid, v[i].s) + v[i].t;
    }
    return true;
}

void check(vector<int> &order){
    vector<Seg> nv;
    for(int i=0; i<n; i++){
        nv.push_back(v[order[i]]);
    }
    int l=0, r = 1e9;
    while(l <= r){
        int mid = (l+r)/2;
        if(valid(nv,mid)){
            ans = max(ans, mid);
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    

}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        int s, d, t;
        cin>>s>>d>>t;
        v.push_back({s,d,t});
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    do{
        check(order);
    }while(next_permutation(order.begin(), order.end()));

    cout << ans << '\n';
}