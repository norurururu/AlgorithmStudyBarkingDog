#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> cards(n);
    for(int i = 0; i < n; i++) {
        cin >> cards[i];
    }
    sort(cards.begin(), cards.end());
    long long maxNum = cards[0];
    int maxCount = 1;
    int currentCount = 1;
    for(int i = 1; i < n; i++) {
        if (cards[i] == cards[i-1]) {
            currentCount++;
        } else {
            currentCount = 1;
        }
        if (currentCount > maxCount) {
            maxCount = currentCount;
            maxNum = cards[i];
        }
    }
    cout << maxNum << '\n';
    return 0;
}
