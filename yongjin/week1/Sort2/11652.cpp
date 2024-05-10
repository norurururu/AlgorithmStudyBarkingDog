#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int,int>> pv;
int n;

bool cmp2(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        auto findNum = find_if(pv.begin(), pv.end(), [num](const pair<int, int>& p) { return p.first == num; });
        if (findNum != pv.end())
            (*findNum).second++;
        else
            pv.emplace_back(num, 1);
    }
    sort(pv.begin(), pv.end(), cmp2);
    cout<<pv[0].first;
}
