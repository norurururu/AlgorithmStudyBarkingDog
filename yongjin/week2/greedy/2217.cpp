#include <iostream>
#include <algorithm>
using namespace std;
int num[100000];
int weightarr[100000];

bool compare(int a,int b){
    return a>b;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    sort(num,num+n,compare);
    int cnt=1;
    for(int i=0;i<n;i++){
        int weight=num[i]*cnt;
        weightarr[i]=weight;
        cnt++;
    }
    cout<<*max_element(weightarr,weightarr+n);
}