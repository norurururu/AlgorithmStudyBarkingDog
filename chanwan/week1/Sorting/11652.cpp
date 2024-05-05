#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    priority_queue <long long int> qu;
    long long int s,pre,now;
    int n;
    cin >>n;
    for(int i=0;i<n;i++){
        cin >> s;
        qu.push(s);
    }

    int count=1;
    int ma=0;
    long long int ans;
    while(!qu.empty()){
        now = qu.top();
        qu.pop();

        if(now==qu.top()){
            count++;
            if(ma<=count){
                ma=count;
                ans = now;
                
            }
        }
        else{
            count=1;
        }
    }
    if(ma<=count){
        ma=count;
        ans = now;
        count = 1;
    }

    cout <<ans;

    return 0;
}