#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
struct cmp
{
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first){
            return a.first<b.first;
        }
        return a.second<b.second;

    }
};
bool cmp2(const int &a,const int &b){
    return a>b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> zuel;
    //priority_queue<int,vector<int>,less<int>> bag;
    //vector<int> bag;
    multiset<int> bag;
    int n,k;
    cin >> n >> k;
    int m,v,c;
    for(int i=0;i<n;i++){
        cin >> m >> v;
        zuel.push({m,v});
    }
    for(int i=0;i<k;i++){
        cin >> c;
        //bag.push_back(c);
        bag.insert(c);
    }
    long long ans=0;
    int max_num=(*prev(bag.end()));
    multiset<int>::iterator it;
    while (!bag.empty()&&!zuel.empty())
    {
        if(zuel.top().first>max_num)zuel.pop();
        else{
            it=bag.lower_bound(zuel.top().first);
            bag.erase(it);
            ans+=zuel.top().second;
            zuel.pop();
            if(bag.empty())break;
            max_num=(*prev(bag.end()));        
        }
    }
    cout << ans;
    return 0;
}