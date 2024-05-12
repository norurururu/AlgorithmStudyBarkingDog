#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int n,a,b;
    cin >>n;
    a=0;
    for(int i=0;i<n;i++){
        cin >> b;
        v.push_back(b);
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<n;i++){
        a = v[i];
        ans= max(ans,a*(n-i));
    }
    cout << ans;
    return 0;
}