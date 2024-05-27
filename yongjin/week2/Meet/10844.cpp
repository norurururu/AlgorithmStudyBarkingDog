#include <algorithm>
#include <iostream>
using namespace std;
int n;
int arr[10];
int main() {
    cin >> n;
    if (n == 1) {
        cout << 9;
        return 0;
    } else {
        for (int k = 1; k < n; k++) {
            // 제일 처음 1로 초기화
            if (k == 1) {
                for (int i = 1; i <= 10; i++) {
                    arr[i] = 1;
                }
            } else {
                int temp[10];
                copy(arr, arr + 10, temp);
                for (int i = 1; i <= 10; i++) {
                    if (i == 1)
                        arr[i] = temp[i + 1];
                    else if (i == 10)
                        arr[i] = temp[i - 1];
                    else
                        arr[i] = temp[i - 1] + temp[i + 1];
                }
            }
        }
    }
    // 합계 계산
    for (auto a : arr) cout << a << " ";
    cout << "\n";
    int sum = 0;
    for (int i = 1; i < 10; i++) {
        sum = sum + (arr[i] );
        cout<<"i= "<<i<<"sum= "<<sum<<"\n";
    }
    sum += arr[10];
    cout << sum;
}