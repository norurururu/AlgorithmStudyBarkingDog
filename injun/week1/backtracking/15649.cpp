#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> arr(10);
bool isused[10];

void func(int k){
    if (k == M) { // base condition
        for (int i=0; i<M; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }

    for (int i=1; i<=N; i++){
        if (isused[i] == false){
            arr[k] = i;
            isused[i] = true;
            func(k+1);
            isused[i] = false;
        }
    }
}

int main(){
    cin >> N >> M;
    ios::sync_with_stdio(0); // using only c++'s i/o
    cin.tie(0); // ties cin and cout
    func(0);
    return 0;
}