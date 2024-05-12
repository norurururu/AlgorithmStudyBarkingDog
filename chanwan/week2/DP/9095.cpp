#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[11];
int sol(int a){
    if(dp[a-1]==-1){
        dp[a-1]=sol(a-1)+sol(a-2)+sol(a-3);
    }
    return dp[a-1];
}
int main(){
    int n,a;
    cin>>n;
    dp[0]=1;
    dp[1]=2;
    dp[2]=4;
    for(int i=3;i<11;i++){
        dp[i]= -1;
    }
    for(int i=0;i<n;i++){
        cin >> a;
        cout << sol(a) << "\n";
    }
}