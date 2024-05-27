#include <bits/stdc++.h>
using namespace std;
int cnt = 0, N, S;
vector<int> arr(30);

void func(int cur, int sum){
    if (cur == N){
        if (sum == S){
            cnt ++;
        }
        return;
    }
    func(cur+1, sum); // if not summing the current element
    func(cur+1, sum+arr[cur]); // if summing the current element
}

int main(){
    cin.tie(0);
    cin >> N >> S;
    for (int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    func(0, 0);
    if (S == 0) cnt --;
    cout << cnt;
    return 0;
}