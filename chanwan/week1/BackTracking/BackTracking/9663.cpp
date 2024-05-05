#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int n,cou;
vector <pair<int,int>> v;

int che(int x,int y){
    int ans=1;
    int a,b;
    for(int i=0;i<x;i++){
        a=v[i].first;
        b=v[i].second;
        if(x+y==a+b){
            ans=0;
            break;
        }
        if(x-y==a-b){
            ans=0;
            break;
        }

        if(y==b){
            ans=0;
            break;
        }        
    }
    return ans;
}

int sol(int k){
    if(k==n){
        cou++;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(che(k,i)==1){
            v[k] = {k,i};
            sol(k+1);
        }
    }
    return 0;
}

int main(){
    cin >>n;
    cou =0;

    for(int i=0;i<n;i++){
        v.push_back({0,0});
    }
    sol(0);
    cout << cou;
    return 0;
}