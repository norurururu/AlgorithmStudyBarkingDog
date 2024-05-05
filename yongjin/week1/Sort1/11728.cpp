#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<int> B(M);
    vector<int> result(N + M);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    for (int i = 0; i < M; ++i)
        cin >> B[i];
    merge(A.begin(), A.end(), B.begin(), B.end(), result.begin());
    for (int i = 0; i < N + M; ++i)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
