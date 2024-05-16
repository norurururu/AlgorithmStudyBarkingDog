#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,s,a,sam;
    cin >> n >>s;
    sam=0;
    v.push_back(0);
    for(int i=0;i<n;i++){
        cin >> a;
        sam+=a;
        v.push_back(sam);
    }
    int ans=0,sum;
    int flag=0;
    if(sam<s){
        cout << 0;
        return 0;
    }
    ans=100001;
    int left=0,right=1;
    while(left<=n){
        sum=v[right]-v[left];
        if(sum<s){
            if(right<n)
            right++;
            else{
                left++;
            }
        }

        else{
            ans=min(ans,right-left);
            right--;
            if(v[right]-v[left]<s){
                left++;
            }

        }
    }
    if(ans==100001){
        cout << 0;
    }
    else
    cout << ans;
    return 0;
}