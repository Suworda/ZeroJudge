#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const ll INF = 4e18;
string s;
int id;

ll calc_exp();
ll calc_item(){
    if(s[id] == 'f'){
        id++;
        ll mx = 0;
        ll mi = INF;
        while(s[id] != ')'){
            id++;
            ll x = calc_exp();
            mx = max(mx, x);
            mi = min(mi, x);
        }
        id++;
        return mx - mi;
    }

    int st = id;
    while('0' <= s[id] && s[id] <= '9') id++;
    return stoll(s.substr(st, id - st));
}

ll calc_exp(){
    vector<ll> v;
    v.push_back(calc_item());
    ll rst = 1;
    while(s[id] == '+' || s[id] == '*'){
        id++;
        if(s[id-1] == '+') v.back() += calc_item();
        else v.push_back(calc_item());
    }
    for(ll x: v) rst *= x;
    return rst;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>s;
    s += ')';
    cout << calc_exp() << '\n';
}