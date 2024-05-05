#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n,coun;
vector <vector<int>> v;
vector <vector<int>> v_cp;

int xr[4]={1,0,-1,0};
int yr[4]={0,-1,0,1};

int comin(){
    int nu=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            nu=max(nu,v_cp[i][j]);
        }
    }
    coun = max(coun,nu);
    return nu;
}

int push_side(int a,int r){
    int x1,y1;
    if(r%2==0){
        y1=a;
        if(r==0)
        x1=0;
        else
        x1=n-1;
    }
    else{
        x1 = a;
        if(r==1)
        y1=n-1;
        else
        y1=0;
    }
    int y2=y1,x2=x1;
    for(int i=0;i<n;i++){
        if(v_cp[y1][x1]==0){
            x2=x1+xr[r];
            y2=y1+yr[r];
            while (x2>=0&&x2<n&&y2>=0&&y2<n)
            {
            if(v_cp[y2][x2]!=0){
                swap(v_cp[y2][x2],v_cp[y1][x1]);
                break;
            }
            x2+=xr[r];
            y2+=yr[r];
            }
        }
        x2=x1+xr[r];
        y2=y1+yr[r];
        while (x2>=0&&x2<n&&y2>=0&&y2<n)
            {

            if(v_cp[y2][x2]!=0){
                if(v_cp[y2][x2]==v_cp[y1][x1]){
                v_cp[y2][x2]=0;
                v_cp[y1][x1]*=2;
                }
                break;
            
            }
            x2+=xr[r];
            y2+=yr[r];
        }
        y1+=yr[r];
        x1+=xr[r];
    }
    return 0;
}

int push_the_side(int r){
    for(int i=0;i<n;i++){
        push_side(i,r);
    }
    return 0;
}

int main(){
vector<int> v2;
int a;
cin >> n;
for(int i=0;i<n;i++){
    v.push_back(v2);
    //v_cp.push_back(v2);
    for(int j=0;j<n;j++){
        cin >> a;
    v[i].push_back(a);
}
}
v_cp.assign(v.size(),vector<int>(v.size()));
copy(v.begin(),v.end(),v_cp.begin());

int l=1024;
coun = 0;
int num1,num2;
for(int i=0;i<l;i++){
        num1 = i;
    copy(v.begin(),v.end(),v_cp.begin());
    for(int j=0;j<5;j++){
        num2=num1%4;
        num1=num1/4;
        push_the_side(num2);
    }
    comin();
}
/*
push_the_side(1);
push_the_side(0);
for(int i=0;i<l;i++){
    num1 = i;
    cout << i <<"case: ";
    for(int j=0;j<5;j++){
        num2=num1%4;
        num1=num1/4;
        cout << num2<<" ";
        }
        cout << "\n";
        }
*/
cout << coun;
/*
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout << v_cp[i][j]<<" ";
    }
    cout << "\n";
    }*/
    return 0;
}