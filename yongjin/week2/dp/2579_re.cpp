#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int score[300][3];
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    score[1][1]=v[0];
    score[1][2]=0;
    score[2][1]=v[1];
    score[2][2]=v[0]+v[1];
    for(int i=3;i<=n;i++){
        score[i][1]=max(score[i-2][1],score[i-2][2])+v[i-1];
        score[i][2]=score[i-1][1]+v[i-1];
    }
    cout<<max(score[n][1],score[n][2]);
}
