#include <iostream>
#include <utility>
#include <vector>
#include <list>
using namespace std;

int n;
list<pair<int, int>> plist;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num1, num2;
        cin >> num1 >> num2;
        plist.emplace_back(num1, num2);
    }
    for (int i = 0; i < n - 1; i++) {
        int j = i + 1;
        while (j < n) {
            if (pv[i].first <= 0) break;
            if (pv[j].first <= 0) {
                j++;
                continue;
            }
            else {
                int temp = pv[i].second;
                pv[j].second -= pv[i].first;
                pv[i].second -= pv[j].first;
                j++;
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(pv[i].second<=0) cnt;;
    }
    cout<<cnt;
}
