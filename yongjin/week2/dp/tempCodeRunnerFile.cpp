#include <iostream>
#include <vector>
using namespace std;
int arr[12];

int main(){
    arr[0]=0;
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    for(int i=4;i<12;i++){
        arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        cout<<arr[n];
    }
    
}