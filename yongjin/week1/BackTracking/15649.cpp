#include <iostream>
using namespace std;

int n, m;
int arr[10];
int issued[10];

int solve(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (!issued[i]) {
            issued[i] = 1;
            arr[k] = i;
            solve(k + 1);
            issued[i] = 0;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    solve(0);
}

