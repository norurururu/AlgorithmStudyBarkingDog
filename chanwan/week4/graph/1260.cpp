#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
    int n,m,t;
vector<vector<int>> v;
bool cash[1000];
void bfs(int a){
queue<int> qu;
qu.push(a);
cash[a]=true;
int num;
while (!qu.empty())
{
    num = qu.front();
    qu.pop();
    cout << num+1<<" ";
    for(int i=0;i<v[num].size();i++){
        if(cash[v[num][i]]==false){
            cash[v[num][i]]=true;
            qu.push(v[num][i]);
        }
    }
}
}

void dfs(int a){
cash[a]=true;
cout << a+1 <<" ";
for(int i=0;i<v[a].size();i++){
    if(cash[v[a][i]]==false){
        dfs(v[a][i]);
    }
}
}

int main(){
    cin >> n >> m>>t;
    v.resize(n);
    int a,b;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }


 for(int i=0;i<n;i++){
    sort(v[i].begin(),v[i].end());
 }
dfs(t-1);
for(int i=0;i<n;i++)
cash[i]=false;
cout <<"\n";
bfs(t-1);
return 0;
}