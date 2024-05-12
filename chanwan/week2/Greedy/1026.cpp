#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool cmp(const int &a,const int &b){
    return a>b;
}

vector<pair<int,int>> v;
vector <int> v_a;
vector <int> v_b;
int main(){
int a,b,n;
cin >> n;
for(int i=0;i<n;i++){
cin >> a;
v_a.push_back(a);
}
for(int i=0;i<n;i++){
cin >> b;
v_b.push_back(b);
}
sort(v_a.begin(),v_a.end());
sort(v_b.begin(),v_b.end(),cmp);
int ans=0;
for(int i=0;i<n;i++){
ans+=v_a[i]*v_b[i];
}
cout << ans;

return 0;
}