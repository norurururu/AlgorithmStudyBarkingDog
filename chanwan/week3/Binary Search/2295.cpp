#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> v;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,u;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> u;
        v.push_back(u);
    }
    sort(v.begin(),v.end());
    int MAX=v[n-1];
    int num;
    int ans=0;
    int is_flag=0;
    vector<int>::iterator iter;
    for(int i=n-1;i>=0;i--){
        if(v[i]*3<=ans)continue;
        for(int j=i;j>=0;j--){
            if(v[i]+v[j]*2<=ans)continue;
            for(int k=j;k>=0;k--){
                num=v[i]+v[j]+v[k];
                if(num>MAX)continue;
                if(num<ans)continue;
                iter=find(v.begin(),v.end(),num);
                if(iter!=v.end()){
                ans=max(ans,*iter);
                }
            }
        }
    }
    cout << ans;
    return 0;
}