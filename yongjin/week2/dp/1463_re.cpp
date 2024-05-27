#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000];
long long n;
int main(){
    cin >> n;
    arr[0]=0;
    arr[1]=0;
    for(int i=2;i<n+1;i++){
        if(i%3==0 && i%2==0){
            arr[i]=
                arr[i/3]+1 <= arr[i/2]+1
                ?(arr[i/3]+1 <= arr[i-1]+1 
                ?arr[i/3]+1
                :arr[i-1]+1)
                :(arr[i/2]+1 <= arr[i-1]+1 
                ?arr[i/2]+1
                :arr[i-1]+1);
        }
        else if(i%3==0){
            arr[i] = arr[i/3]+1 <= arr[i-1]+1 
            ?arr[i/3]+1
            :arr[i-1]+1
            ; 
        }
        else if(i%2==0){
            arr[i] = arr[i/2]+1 <= arr[i-1]+1 
            ?arr[i/2]+1
            :arr[i-1]+1
            ;
        }
        else arr[i] = arr[i-1]+1;    
    }
    cout<<arr[n];
    
}