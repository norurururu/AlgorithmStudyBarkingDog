#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int b;

int main(){
    int m,n;
    cin >>m>>n;
    vector <int> v;
    vector <int>::iterator st,en;

    double a = sqrt(n);
    for(int i=0;i<=n;i++){
        v.push_back(1);
    }
    v[0] = 0;
    v[1] = 0;
    for(int i=0;i<a+1;i++){
        if(v[i]==1){
            for(int j=i*i;j<=n;j+=i){
                v[j]=0;
            }
        }
        //v.erase(remove_if(v.begin(),v.end(),[](int x) -> bool{return(x!=b&&x%b==0);}),v.end());
        
    }


    for(int i=m;i<=n;i++){
        if(v[i]==1){
        cout << i << "\n";
    }}
    return 0;
}