#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int dp[1000000]={0,};
queue<int> qu;
stack<int> sta;
int cou;

int sol(int a){
    if(dp[a]!=0){
        return dp[a];
    }
    int mi = sol(a-1);
    if(a%3==0){
        mi=min(sol(a/3),mi);
    }
    if(a%2==0){
        mi=min(sol(a/2),mi);
    }
    
    dp[a]=1+mi;

    return dp[a];
}

int main(){
int n;
cin >>n;
sta.push(1);
cou=2;
dp[1]=1;
int ans=sol(n);
ans;
cout << ans-1<<"\n";
int mi=ans-1;
int now=n;

while(now>0){
    cout << now<<" ";

if(dp[now-1]==mi){
    now=now-1;
    mi--;
    continue;
}

if(now%3==0){
    if(dp[now/3]==mi){
        now = now/3;
        mi--;
        continue;
    }
}

if(now%2==0){
    if(dp[now/2]==mi){
        now = now/2;
        mi--;
        continue;
    }
}
}







return 0;
}