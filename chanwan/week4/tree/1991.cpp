#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
vector<vector<int>> v;

void cal(int n){

    cout << char('A'+v[n][0]);
}

void forn(int n){
cal(n);
if(v[n][1]>=0){
    forn(v[n][1]);
}
if(v[n][2]>=0){
    forn(v[n][2]);
}
}
void mid(int n){
if(v[n][1]>=0){
    mid(v[n][1]);
}
cal(n);
if(v[n][2]>=0){
    mid(v[n][2]);
}
}

void lest(int n){
if(v[n][1]>=0){
    lest(v[n][1]);
}
if(v[n][2]>=0){
    lest(v[n][2]);
}
cal(n);
}

int main(){
vector<int> v1;
int n;
char a,b,c;
cin >> n;
for(int i=0;i<n;i++){
    cin >> a >> b >> c;
    v.push_back(v1);
    v[i].push_back(a-'A');
    v[i].push_back(b-'A');
    v[i].push_back(c-'A');
}
sort(v.begin(),v.end());

forn(0);
cout <<"\n";
mid(0);
cout << "\n";
lest(0);
cout << "\n";

return 0;
}