#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int xr[4]= {1,0,-1,0};
int yr[4]= {0,-1,0,1};

vector <vector<int>> v;
vector <vector<int>> sol_v;

vector <pair<int,int>> cc;
vector <int> cc_fo;
vector <int> cc_type;
int x,y,num_cc,countcc;

int foward2(int y1,int x1,int r){
    while ((y1>=0)&&(x1>=0)&&(x1<x)&&(y1<y)&&sol_v[y1][x1]!=6)
    {
        if(sol_v[y1][x1]==0){
            sol_v[y1][x1]=-1;
        }
        x1+=xr[r];
        y1+=yr[r];
        
    }
    return 0;
}

int coun(){
    copy(v.begin(),v.end(),sol_v.begin());
    for(int i=0;i<num_cc;i++){
        int ty=cc_type[i];
        if(ty==2){
            foward2(cc[i].first,cc[i].second,(2+cc_fo[i])%4);
            foward2(cc[i].first,cc[i].second,cc_fo[i]);

        }
        else{
            if(ty>1)
            ty--;
            for(int j=0;j<ty;j++){
                foward2(cc[i].first,cc[i].second,(cc_fo[i]+j)%4);

            }
        }
    }
    int ans = 0;
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            if(sol_v[i][j]==0)
            ans++;
        }
    }
    countcc = min(countcc,ans);
return ans;
}

int sol(int a){
    if(a==num_cc){

        coun();
        return 0;
    }
    int ty=cc_type[a];
    int ras=4;
    if(ty==5)ras=1;
    if(ty==2)ras=2;
    for(int i=0;i<ras;i++){
        cc_fo[a]=i;
        sol(a+1);
    }

return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
int a;
cin >> y >> x;
num_cc=0;
countcc = 100;
vector <int> v2;
for(int i=0;i<y;i++){
    v.push_back(v2);
    for(int j=0;j<x;j++){
        cin>>a;
        if(a>0&&a<6){
            num_cc++;
            cc_fo.push_back(0);
            cc_type.push_back(a);
            cc.push_back({i,j});
        }
        v[i].push_back(a);
    }
}

//sol(0);
    sol_v.assign(v.size(),vector<int>(v.size()));
    sol(0);
    //copy(v.begin(),v.end(),sol_v.begin());
    /*
for(int i=0;i<y;i++){
    for(int j=0;j<x;j++){
        cout << sol_v[i][j]<<" ";
    }
    cout << "\n";
    }*/
    cout << countcc;

return 0;
}