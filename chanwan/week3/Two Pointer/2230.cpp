#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int gap(int a,int b){
    a = a-b;
    if(a<0)
    a= -a;
    return a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
int n,m,a;
cin >> n >> m;
int ans=2000000001;
vector <int> lo;
for(int i=0;i<n;i++){
    cin >> a;
    lo.push_back(a);
}
sort(lo.begin(),lo.end());
vector<int>::iterator st,en;
st=lo.begin();
int j=1;
for(int i=0;i<n-1;i++){
    for(;j<n;j++){
        if(gap(lo[i],lo[j])>=m){
            ans = min(ans,gap(lo[i],lo[j]));
            break;
        }
    }
}
cout << ans;
return 0;
}