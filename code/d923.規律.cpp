#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int f(double x, double y, int mi, int mx, int r, int c, int v, int d){
    // cerr << x << ' ' << y << ' ' << mi << ' ' << mx << ' ' << r << ' ' << c << ' ' << v << ' ' << v <<  ' ' << d << '\n';
    if(mi == mx) return mi;

    if(r < x && c < y){
        return f(x-d, y-d,mi,mx-3*v,r,c,v/4,d/2);
    }else if(r < x && c > y){
        return f(x-d, y+d,mi+2*v,mx-v,r,c,v/4,d/2);

    }else if(r > x && c < y){
        return f(x+d, y-d,mi+3*v,mx,r,c,v/4,d/2);
        
    }else if(r > x && c > y){
        return f(x+d, y+d,mi+v,mx-2*v,r,c,v/4,d/2);
        
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, c;
    cin>>r>>c;
    cout << f((1LL<<29)+0.5, (1LL<<29)+0.5, 1,(1LL<<60),r,c,(1LL<<58), (1LL<<28)) << '\n';

}