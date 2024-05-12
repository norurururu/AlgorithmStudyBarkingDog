#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int cou,s,n;
vector <int> v;
int lo[22]={0,};
int sol(int k){
    if(k==n){
        int sum=0;
        for(int i=0;i<n;i++){
            if(lo[i]==1){
                sum += v[i];
            }
        }
        if(sum==s)
        cou++;
        return 0;
    }
    lo[k]=0;
    sol(k+1);
    lo[k]=1;
    sol(k+1);
    return 0;
}

int main(){
    int a;
    cin >> n >> s;
    for(int i=0;i<n;i++){
        cin >> a;
        v.push_back(a);
    }
    cou = 0;
    sol(0);
    if(s==0){
        cou--;
    }
    cout << cou;
    return 0;
}