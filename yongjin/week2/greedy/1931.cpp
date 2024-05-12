#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
vector<pair<int, int>> pv;
int N;
int main() {
    cin >> N;
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        pv.push_back({b, a});
    }
    sort(pv.begin(), pv.end());
    //어차피 정렬은 되어 잇다
    int cnt=0;
    int cur=0;
    for(int i=0;i<N;i++){
        if(cur>pv[i].second)continue;
        cur=pv[i].first;
        cnt++;
    }
    cout<<cnt;
}
