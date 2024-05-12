#include <iostream>

using namespace std;
int dp[301][2];
int sta[301];
int solve0(int a);
int solve1(int a){
    if(a<0){
        return 0;
    }
    else if(dp[a][1]!=-1){
        return dp[a][1];
    }
    else{
        dp[a][1]=solve0(a-1)+sta[a];
    }
    return dp[a][1];
}
int solve0(int a){
    if(a<0){
        return 0;
    }
    else if(dp[a][0]!=-1){
        return dp[a][0];
    }
    else{
        dp[a][0]=max(solve1(a-2),solve0(a-2))+sta[a];
    }
    return dp[a][0];
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        dp[i][0]=-1;
        dp[i][1]=-1;
        cin >> sta[i];
    }
    dp[0][0]=sta[0];
    int c = max(solve1(n-1),solve0(n-1));
    cout << c;
}