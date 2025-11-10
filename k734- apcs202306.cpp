#include <iostream>
#include <cmath>
using namespace std;

long long sum(long long x){
    if(x==0) return 0;
    long long a=sqrt(x)+2;
    while(a*a>x) a--;
    return (a-1)*3+(x-a*a)/a+1;
}

void solve(){
    long long l,r;
    cin>>l>>r;
    cout<<sum(r)-sum(l-1)<<'\n';
    // for(int i=1; i<=r; i++){
    //     if(i%(int)sqrt(i)==0) cout<<i<<'\n';
    // }

}

int main(){
    ios::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--)solve();
}
