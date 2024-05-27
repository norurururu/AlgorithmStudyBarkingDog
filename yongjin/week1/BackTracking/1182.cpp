#include <iostream>
using namespace std;

int n, s, cnt = 0;
int numlist[21];

void solve(int idx, int sum) {
    if (idx == n) return; 
    if (sum + numlist[idx] == s) cnt++; 
    
    solve(idx + 1, sum); 
    solve(idx + 1, sum + numlist[idx]); 
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> numlist[i];
    }

    solve(0, 0);

    cout << cnt;
    return 0;
}