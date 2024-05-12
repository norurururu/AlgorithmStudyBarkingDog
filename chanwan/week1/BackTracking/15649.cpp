#include <iostream>

using namespace std;
int n,m;
void out1(int lst[]){
    for(int i=m-1;i>=0;i--){
        cout << *(lst-i) <<" ";
    }
    cout <<"\n";
    return;
}

void sol(int a[],int c){
    if(c==m){
        out1(a);
        return;
    }
    int k= *a;
    int f = 0;
    for(int i=1;i<=n;i++){
        f=0;
        for(int j=0;j<c;j++){
            if(*(a-j)==i){
                f=1;
            }
        }
        if(f==1)continue;
        *(a+1)=i;
        sol(a+1,c+1);
    }
}

int main(){
    cin >> n >> m;
    int lst[m+1];
    lst[0]=0;
    sol(lst,0);
    return 0;
}