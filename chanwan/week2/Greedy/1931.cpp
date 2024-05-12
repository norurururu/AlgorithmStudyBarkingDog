#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,a,b;
    vector<pair<int,int>> v;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        v.push_back({b,a});
    }
    sort(v.begin(),v.end());

    
    vector<pair<int,int>>::iterator st,en,now;
    st=v.begin();
    en=v.end();
    int minnum=0,count=0;
    
    for(st=v.begin();st!=en;st++)
    {

    if((*st).second>=minnum){
    count++;
    minnum=(*st).first;
    }
    }
    
    cout << count;
    return 0;
}