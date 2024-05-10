#include<iostream>
using namespace std;
int n;
int arr[1001];
int main(){
    arr[1]=1;
    arr[2]=2;
    cin>>n;
    if(n==1){
        cout<<1;
        return 0;
    }
    if(n==2){
        cout<<2;
        return 0;
    }
    for(int i=3;i<=n;i++){
        arr[i]=(arr[i-1]+arr[i-2])%10007;
    }
    cout<<arr[n]%10007;
}