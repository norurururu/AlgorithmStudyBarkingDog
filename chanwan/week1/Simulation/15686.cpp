#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int m,n,chi_count,hus_count;
vector <pair<int,int>> chi;
vector <pair<int,int>> hus;
int los[20]={0,};
int coun;
int abs(int a,int b){
    int n= a-b;
    if(n<0){
        n= -n;
    }
    return n;
}

int sol(){
    
    int num,sum=0;
    for(int j=0;j<hus_count;j++){
        num=123456789;
    for(int i=0;i<m;i++){
        num = min(num,abs(chi[los[i]].first,hus[j].first)+abs(chi[los[i]].second,hus[j].second));

    }
    sum+=num;
    }
    return sum;
}

int picki(int t,int k){
if(k==m){
    coun=min(sol(),coun);
    return 0;
}

for(int i=t+1;i<chi_count;i++){
    los[k]=i;
    picki(i,k+1);
}

return 0;
}

int main(){
    int a,b;
    cin >> n >>m;
    chi_count=0;
    hus_count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a;
            if(a==1){
                hus_count++;
                hus.push_back({i,j});
            }
            else if(a==2){
                chi_count++;
                chi.push_back({i,j});                
            }
        }
    }
    coun=123456789;
    picki(-1,0);

    cout << coun;
    return 0;
}