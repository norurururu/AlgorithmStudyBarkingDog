#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t, m, n, x, y;
    cin >> t;
    while (t--) {
        cin >> m >> n >> x >> y;
        if(m==x) x=0;
        if(n==y) y=0;
        vector<int> v;
        bool xfind = false;
        for (int i = 0; i < m ; i++) {
            if (i%m  == x) {
                v.push_back(i);
                xfind = true;
                break;
            }
        }
        if (xfind == false) {
            cout << -1 << "\n";
            continue;
        }
        int i = 0;
        int temp = v[0] % n;
        while (1) {
            if (v[i]!=0 && v[i] % n == y) {
                cout << v[i] << "\n";
                break;
            }
            if (i != 0 && (v[i] %n == temp)) {
                cout << "-1" << "\n";
                break;
            }
            v.push_back(v[i] + m);
            i++;
        }
    }
}