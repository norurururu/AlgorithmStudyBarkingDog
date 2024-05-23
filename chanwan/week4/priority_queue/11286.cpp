#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int gdb(int a){
    if(a<0)return -a;
    return a;
}

struct cmp
{
    bool operator()(int a,int b){
        if(gdb(a) == gdb(b))
        return a>b;
        return gdb(a) > gdb(b);
    
    }
};


int main(){
    priority_queue<int,vector<int>,cmp> qu;
    int n;
    cin >>n;
    int a;
    for(int i=0;i<n;i++){
        cin >> a;
        if(a==0){
            if(qu.empty())
            cout << 0 <<"\n";
            else{
                cout << qu.top()<<"\n";
                qu.pop();
            }
        }
        else{
            qu.push(a);
        }
    }

    
    return 0;
}