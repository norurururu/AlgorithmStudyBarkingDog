#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int arr[51];
vector<pair<int, int>> pv;
bool cmp1(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        pv.push_back({b, i});
    }

    sort(arr, arr + n);
    //for (auto ar : arr) cout << ar << " ";
    //cout << "\n";
    sort(pv.begin(), pv.end(), cmp1);
    //for (auto ar : pv) cout << ar.first << " " << ar.second << " ";
    //cout << "\n";
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + (pv[i].first * arr[i]);
    }
    cout << sum;
}