#include <iostream>
#include <vector>
using namespace std;

int n,m;
int main(){
    cin>>n>>m;
    vector<bool> v(m+1,true);
    v[1]=false;
    for(int i=2;i*i<=m;i++){
        if(v[i]==false) continue;
        for(int j=i*i;j<=m;j+=i){
            v[j]=false;
        }
    }
    for(int i=n;i<=m;i++){
        if(v[i]==true) cout<<i<<"\n";
    }
}