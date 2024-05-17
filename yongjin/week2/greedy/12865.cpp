#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int n,k,w,v;
vector<pair<int,int>> pv;
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>w>>v;
        pv.push_back({w,v});
    }
    
}