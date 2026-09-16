#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

}#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int N = 100005;
int n,m;
int parent[N];
int size[N];

void merge()

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    cin>>n>>m;
    iota(parent, parent+n+1, 0);
    while(m--){
        int ty,p,q;
        if(ty == 1){
            cin>>p>>q;
            merge(p,q);
        }
        else if(ty == 2){
            cin>>p>>q;
            move(p,q);
        }
        else{
            cin>>p;
            print(p);
        }
    }

}