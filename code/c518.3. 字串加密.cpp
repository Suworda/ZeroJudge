// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define ll long long

// ll st[128];
// int id[128];
// string id_to_c(128,' ');
// string change;

// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n,m;
//     cin>>n>>m;
//     string p, s, t;
//     cin>>p>>s>>t;

//     int cur_id = 0;
//     for(int i=0; i<128; i++){
//         if(isalpha(i) || isdigit(i)){
//             id[i] = cur_id++;
//             id_to_c[id[i]] = char(i);
//             st[i] |= (1LL<<id[i]);
//         }
//     }

//     for(int i=0; i<m; i++){
//         char x = s[i], y = t[i];
//         if(x == y) continue;
//         st[y] |= st[x];
//         st[x] = 0;
//     }

//     change.resize(128, '#');
//     for(int i=0; i<128; i++){
//         for(int j=0; j<62; j++){
//             if((st[i] >> j) & 1){
//                 change[id_to_c[j]] = char(i);
//             }
//         }
//     }

//     for(int i=0; i<n; i++) cout << change[p[i]];
//     cout << '\n';
    

// }

#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string p, s, t;
    cin >> p >> s >> t;

    char mp[128];

    for (int i = 0; i < 128; i++)
        mp[i] = char(i);

    for (int i = m - 1; i >= 0; i--)
        mp[s[i]] = mp[t[i]];

    for (char c : p)
        cout << mp[c];

    cout << '\n';
}