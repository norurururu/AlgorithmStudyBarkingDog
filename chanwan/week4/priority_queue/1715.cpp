#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n,a;
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> qu;
    for(int i=0;i<n;i++){
        cin >>a;
        qu.push(a);
    }
    int ans=0,now1=0,now2;

    while (qu.size()>1)
    {

        now1=qu.top();
        qu.pop();
        now2=qu.top();
        qu.pop();
        ans+=now1+now2;
        qu.push(now1+now2);
    }

    cout << ans;
    return 0;
}