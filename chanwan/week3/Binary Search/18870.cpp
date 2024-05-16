#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,a;
    cin >> n;
    int lo[n];
    vector <int>x;
    unordered_map <int,int> ma;
    for(int i=0;i<n;i++){
        cin >> lo[i];
        x.push_back(lo[i]); 
    }
    sort(x.begin(),x.end());
    ma.insert({x[0],0});
    int count = 1;
    for(int i=1;i<n;i++){
        if(x[i-1]!=x[i]){
            ma.insert({x[i],count});
            count++;
        }
    }
    unordered_map <int,int>::iterator co;
    for(int i=0;i<n;i++){
        co = ma.find(lo[i]);
        cout << (*co).second<<" "; 
    }   
    return 0;
}
