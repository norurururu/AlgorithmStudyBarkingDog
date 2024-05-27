#include <bits/stdc++.h>
using namespace std;
int cnt = 0, N;
bool isused1[50];
bool isused2[50];
bool isused3[50];

void func(int cur){
    if (cur == N){
        cnt ++;
        return;
    }
    for (int i=0; i<N; i++){
        if (isused1[i] == true || isused2[cur+i] == true || isused3[cur-i+N-1] == true) continue;
        isused1[i] = true;
        isused2[cur+i] = true;
        isused3[cur-i+N-1] = true;
        func(cur+1);
        isused1[i] = false;
        isused2[cur+i] = false;
        isused3[cur-i+N-1] = false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    func(0);
    cout << cnt;
    return 0;
}