#include <iostream>
#include <vector>

using namespace std;

vector <vector<int>> v;
vector <int> cash;
int solve(int n){
    cash[n]=1;
    vector<int>::iterator en;
    en = v[n].end();
    for(auto it=v[n].begin();it!=en;it++){
        if(cash[*it]==0){
            solve(*it);
        }
    }
    return 0;
}
int main(){
    vector<int> v2;
    int n,m,a,b;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        v.push_back(v2);
        cash.push_back(0);
    }
    for(int i=0;i<m;i++){
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int count = 0;
    vector<int>::iterator st,en;
    for(int i=0;i<n;i++){
        if(cash[i]==0){
            count++;
            solve(i);
        }
    }

    cout << count;
        return 0;

}