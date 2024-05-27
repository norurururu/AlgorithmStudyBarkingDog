#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int,int>> paiv;
vector<int> numv;
vector<int> sumv;
int n,m;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        numv.push_back(num);
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        paiv.push_back({a,b});
    }
    sumv.push_back(numv[0]);
    for(int i=1;i<n;i++){
        sumv.push_back(numv[i]+sumv[i-1]);
    }
    for(int i=0;i<m;i++){
        int a = paiv[i].first;
        int b = paiv[i].second;
        cout<<sumv[b-1]-sumv[a-1]+numv[a-1]<<"\n";
    }
}