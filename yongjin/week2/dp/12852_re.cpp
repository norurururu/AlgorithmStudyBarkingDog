#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> vv;

int main(){
    int n;
    cin>>n;
    vv[1].push_back(1);
    for(int i=2;i<=n;i++){
        if(i%2==0 && i%3==0){
            vv[i].push_back(vv[i/3]);
            vv[i].push_back(vv[i/2]);
            vv[i].push_back(vv[i-1]);
            vv[i].push_back(i);
            sort(vv[i].begin(), vv[i].end());
            vv[i].erase(unique(vv[i].begin(),vv[i].end()), vv[i].end());
        }
        if(i%3==0){
            vv[i].push_back(vv[i/3]);
            vv[i].push_back(vv[i-1]);
            vv[i].push_back(i);
            sort(vv[i].begin(), vv[i].end());
            vv[i].erase(unique(vv[i].begin(),vv[i].end()), vv[i].end());
        }
        if(i%2==0){
            vv[i].push_back(vv[i/2]);
            vv[i].push_back(vv[i-1]);
            vv[i].push_back(i);
            sort(vv[i].begin(), vv[i].end());
            vv[i].erase(unique(vv[i].begin(),vv[i].end()), vv[i].end());
        }
        else{
            vv[i].push_back(vv[i-1]);
            vv[i].push_back(i);
            sort(vv[i].begin(), vv[i].end());
            vv[i].erase(unique(vv[i].begin(),vv[i].end()), vv[i].end());
        }
    }
    if(n%3==0 && n%2==0){cout<<min({vv[n-1].size(),vv[n/2].size(),vv[n/3].size()});}
    if(n%3==0){cout<<min({vv[n-1].size(),vv[n/3].size()});}
    if(n%2==0){cout<<min({vv[n-1].size(),vv[n/2].size()});}
    else{cout<<vv[n-1].size();}
    for(auto v:vv[n])cout<<v<<" ";
}