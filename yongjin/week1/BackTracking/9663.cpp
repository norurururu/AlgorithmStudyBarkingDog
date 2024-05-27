#include <iostream>
using namespace std;

int n, cnt = 0;
int row[15];                     
bool col[15], add[30], sub[30];  

void solve(int x) {
    if (x == n) {  
        cnt++;
        return;
    }
    for (int y = 0; y < n; y++) {  
        if (!col[y] && !add[x + y] &&
            !sub[x - y + n - 1]) {  
            row[x] = y;
            col[y] = add[x + y] = sub[x - y + n - 1] = true;
            solve(x + 1);  
            col[y] = add[x + y] = sub[x - y + n - 1] = false;  
        }
    }
}

int main() {
    cin >> n;
    solve(0);
    cout << cnt;
    return 0;
}
