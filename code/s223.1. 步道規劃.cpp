#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct P{
    int d, h;

    bool operator< (const P &b) const{
        return d < b.d;
    }
};

int n,k;

bool valid(vector<int> &v, int mid){
    int cur_seg = 1;
    int cur_val = 0;
    for(int i=0; i<v.size(); i++){
        cur_val += v[i];
        if(cur_val > mid){
            cur_val = 0;
            cur_seg++;
        }
    }

    return cur_seg <= k;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    vector<P> p(n);
    for(int i=0; i<n; i++) cin>>p[i].d;
    for(int i=0; i<n; i++) cin>>p[i].h;

    sort(p.begin(), p.end());

    vector<int> v;
    for(int i=1; i<n; i++) v.push_back((p[i].d - p[i-1].d + max(0LL, 2 * (p[i].h - p[i-1].h))));

    int ans = 2e18;
    int l = 0, r = 2e18;
    while(l <= r){
        int mid = (l+r)/2;
        if(valid(v,mid)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid + 1;
        }
    }

    cout << ans << '\n';


}