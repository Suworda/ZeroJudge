#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>

using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n,s;
        cin>>n>>s;
        cout << __builtin_ctz(s & (-s)) + 1 << '\n';
    }

}