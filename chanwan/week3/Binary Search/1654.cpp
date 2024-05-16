#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
vector<int> v;
int main(){
    long long int k,n,a,right;
    right =0;
    cin >> k >> n;
    for(int i=0;i<k;i++){
        cin >> a;
        right=max(right,a);
        v.push_back(a);
    }
    long long int left=1,mid,ans=0;
    long long int count;
    while (right>left)
    {
        count=0;
        mid = (right+left)/2;
        for(int i=0;i<k;i++){
            count+=(v[i]/mid);
            if(count>=n)break;
        }
        if(count<n){
            right= mid-1;
        }
        else{
            ans=max(ans,mid);
            left = mid+1; 
        }
    }
    cout << ans;
    return 0;
}