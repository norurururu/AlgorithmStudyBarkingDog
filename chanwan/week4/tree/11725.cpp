#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(){
    int n,a,b;
    cin >>n;
    int cash[n];
    vector <vector<int>> v;
    vector<int> v2;
    queue<int> lo;

    for(int i=0;i<n;i++){
        v.push_back(v2);
        cash[i]=0;
    }
    for(int i=1;i<n;i++){
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    cash[0]=-1;
    lo.push(0);
    int add,min;
    vector<int>::iterator st,en;
    while(lo.size()>0){
        add = lo.front();
        lo.pop();
        st = v[add].begin();
        en = v[add].end();
        for(auto it=st;it!=en;it++){
            if(cash[*it]==0){
                cash[*it]=add+1;
                lo.push(*it);
            }
        }
    }
    for(int i=1;i<n;i++){
        cout << cash[i]<<"\n";
    }
    return 0;
}