#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector <vector<vector <int>>> v_lo;
vector <pair<int,int>> v_ran;
vector <vector<int>> v_main;
int spi[10][10]={0,};
int spi_or[10][10]={0,};

int m,n,k;

void cle(){
    //판뗴기 초기화
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            spi[i][j]=0;
        }
    }
}
int rang_fit(int y,int x,int y1,int x1){
    //조각 끼워넣기
    for(int i=0;i<y1;i++){
        for(int j=0;j<x1;j++){
            if(spi[i][j]==1){
                v_main[i+y][j+x]=1;
            }}}
    return 0;
}
int rang(int y,int x,int y1,int x1){
    //조각이 위치에 들어맞는지
    int ans=1;
    for(int i=0;i<y1;i++){
        for(int j=0;j<x1;j++){
            if(spi[i][j]==1){
                if(v_main[i+y][j+x]==1){
                    ans=0;
                    return 0;
                }
            }
        }
    }
    return ans;
}
int fit2put(int k,int r){
    //spi[][]에다 돌린 조각을 맞춰넣기
    cle();
    int y1=v_ran[k].first,x1=v_ran[k].second;
    if(r==0){
    for(int i=0;i<y1;i++){
        for(int j=0;j<x1;j++){
            spi[i][j]=v_lo[k][i][j];
        }
    }
    }
    if(r==1){
    for(int i=0;i<y1;i++){
        for(int j=0;j<x1;j++){
            spi[j][y1-i-1]=v_lo[k][i][j];
        }
    }
    }
    if(r==2){
    for(int i=0;i<y1;i++){
        for(int j=0;j<x1;j++){
            spi[i][j]=v_lo[k][y1-i-1][x1-j-1];
        }
    }
    }
    if(r==3){
    for(int i=0;i<y1;i++){
        for(int j=0;j<x1;j++){
            spi[j][y1-i-1]=v_lo[k][y1-i-1][x1-j-1];
        }
    }
    }

    return 0;
}
int solve_r(int k){
    int y1,x1;

    for(int u=0;u<4;u++){
    fit2put(k,u);
    if(u%2==0){
    y1=v_ran[k].first,x1=v_ran[k].second;
    }
    else{
    x1=v_ran[k].first,y1=v_ran[k].second;
    }
    
    for(int i=0;i<=m-y1;i++){
        for(int j=0;j<=n-x1;j++){
            if(rang(i,j,y1,x1)==1){
                rang_fit(i,j,y1,x1);
                return 0;
            }
        }
    }
    }
    return 0;

}

int main(){
    cin >> m >> n >>k;
    int a,b,c;
    vector<vector<int>> v2;
    vector<int> v1;
    for(int i=0;i<m;i++){
    v_main.push_back(v1);
    for(int j=0;j<n;j++){
        v_main[i].push_back(0);
    }
    }
    for(int i=0;i<k;i++){
        v_lo.push_back(v2);
        cin >> a >> b;
        v_ran.push_back({a,b});
        for(int j=0;j<a;j++){
            v_lo[i].push_back(v1);
            for(int s=0;s<b;s++){
                cin >> c;
                v_lo[i][j].push_back(c);
            }
        }
    }



    for(int i=0;i<k;i++){
        solve_r(i);
    }
    int count_s=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(v_main[i][j]==1)count_s++;
        }
    }

    cout << count_s<<"\n";

    
    return 0;
}