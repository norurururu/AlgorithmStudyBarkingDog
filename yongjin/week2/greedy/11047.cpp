#include<iostream>
#include<numeric>
using namespace std;

int N,M;
int arr[10];
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int sum=0;
    for(int i=N-1;i>=0;i--){
        sum+=M/arr[i];
        M=M%arr[i];
    }
    cout<<sum;
    
}