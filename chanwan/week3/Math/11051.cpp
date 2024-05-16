#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int MOD=10007;
int dp[1010][1010];
int main(){
    int n,k;
    cin >> n >>k;
    int ans=1;
    dp[0][0]=1;
    for(int i=0;i<=n+1;i++){
        for(int j=1;j<=i+1;j++){
            dp[i+1][j]=(dp[i][j]+dp[i][j-1])%MOD;
        }
    }

    cout << dp[n+1][k+1];
    return 0;
}