#include <iostream>

using namespace std;
int dp[1001];
int solve(int a){
    if(dp[a]!=-1){
    }
    else{
        dp[a] = (solve(a-1)+solve(a-2))%10007;
    }
    return dp[a];

}
int main(){
    int n,count;
    count =0;
    cin >> n;
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    count=solve(n);
    cout << count<<"\n";
    return 0;
}