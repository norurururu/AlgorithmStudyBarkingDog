#include <iostream>
#include <algorithm>

using namespace std;
int dp[1234567];
int solve1(int n){
    if(dp[n]==-1){
        if(n%6==0){
            dp[n]=min({solve1(n/3),solve1(n/2),solve1(n-1)})+1;
        }
        else if(n%3==0){
            dp[n]=min(solve1(n/3),solve1(n-1))+1;
        }
        else if(n%2==0){
            dp[n]=min(solve1(n/2),solve1(n-1))+1;
        }
        else{
            dp[n]=solve1(n-1)+1;
        }
    }
    return dp[n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<=n;i++){
        dp[i]= -1;
    }
    dp[1]=0;
    cout << solve1(n);
    return 0;
}