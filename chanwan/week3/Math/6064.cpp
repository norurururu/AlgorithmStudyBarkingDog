#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int sol(int a,int b,int x,int y){
    int a1=x;
    int b1=y;
    int manum=a*b/__gcd(a,b);
    while (a1<=manum||b1<=manum)
    {
    if(a1==b1)break;
    if(a1<b1){
        a1=a1+a;
    }
    else{
        b1=b1+b;
    }
    }
    
    if(a1==b1){
        if(a1==0){
            return manum;
        }
        return a1;
    }
    return -1;
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,m,n,x,y,ans;
    cin >>t;
    int manum,minum;
    for(int i=0;i<t;i++){
        cin >> m >> n >> x >> y;
        ans=sol(m,n,x,y);
        if(ans==-1){
            cout << -1<<"\n";
        }
        else{
            cout << ans <<"\n";
        }
    }
    return 0;
}