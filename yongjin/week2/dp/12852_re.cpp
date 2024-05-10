#include <iostream>
#include <algorithm>
using namespace std;
int cnt[1000001];
int num[1000001];

int main(){
    int n;
    cin>>n;
    cnt[1]=0;
    cnt[2]=1;
    cnt[3]=1;
    num[1]=0;
    num[2]=1;
    num[3]=1;
    for(int i=3;i<=n;i++){
        if(i%3==0 && i%2==0){
            cnt[i]=min({cnt[i/3],cnt[i/2],cnt[i-1]})+1;
            if(cnt[i]==cnt[i/3]+1) num[i]=i/3;
            if(cnt[i]==cnt[i/2]+1) num[i]=i/2;
            if(cnt[i]==cnt[i-1]+1) num[i]=i-1;
        }
        else if(i%3==0){
            cnt[i]=min({cnt[i/3],cnt[i-1]})+1;
            if(cnt[i]==cnt[i/3]+1) num[i]=i/3;
            if(cnt[i]==cnt[i-1]+1) num[i]=i-1;
        }
        else if(i%2==0){
            cnt[i]=min({cnt[i/2],cnt[i-1]})+1;
            if(cnt[i]==cnt[i/2]+1) num[i]=i/2;
            if(cnt[i]==cnt[i-1]+1) num[i]=i-1;
        }
        else{
            cnt[i]=cnt[i-1]+1;
            if(cnt[i]==cnt[i-1]+1) num[i]=i-1;
        }
    }
    cout<<cnt[n]<<"\n";
    int i=n;
    while(1){
        cout<<i<<" ";
        if(i==1)break;
        i = num[i];
    }
}