#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int mtod[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
    int a,b;
    int y1,y2,m1,m2,d1,d2;
    cin>>y1>>m1>>d1>>y2>>m2>>d2;
    a=(y1-1)*365+mtod[m1-1]+d1;
    b=(y2-1)*365+mtod[m2-1]+d2;
    for(int i=0; i<=y1; i++){
        if((i%400==0) || (i%4==0 && i%100 != 0)){
            if(i==y1 && m1>2){
                a++;
            }else if(i!=y1){
                a++;
            }
        }
    }

    for(int i=0; i<=y2; i++){
        if(i%400==0 || (i%4==0 && i%100 != 0)){
            if(i==y2 && m2>2){
                b++;
            }else if(i!=y2){
                b++;
            }
        }
    }

    int ans=abs(a-b);
    // int cnt=0;
    // for(int i=min(y1,y2)+1; i<=max(y1,y2)-1; i++){
    //     if(i%400==0 || i%4==0 && i%100 != 0){
    //         ans++;
    //     }
    // }
    cout<<ans<<'\n';
}
/*
2024 3 1
2021 3 1
*/

