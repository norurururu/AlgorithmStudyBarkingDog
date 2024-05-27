#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<vector<int>> board;

int row(int x, int y, int idx) {
    // 1:왼쪽 2:오른쪽 3:왼쪽 채우기 4:오른쪽 채우기
    if (idx == 1) {
        int sum = 0;
        for (int i = y; i >= 0; i--) {
            if (board[x][i] == 0) sum++;
            if (board[x][i] == 6) return sum;
        }
        return sum;
    }
    if (idx == 2) {
        int sum = 0;
        for (int i = y; i < m; i++) {
            if (board[x][i] == 0) sum++;
            if (board[x][i] == 6) return sum;
        }
        return sum;
    }
    if (idx == 3) {
        for (int i = y; i >= 0; i--) {
            if (board[x][i] == 0) board[x][i] = 7;
            if (board[x][i] == 6) return 0;
        }
    }
    if (idx == 4) {
        for (int i = y; i < m; i++) {
            if (board[x][i] == 0) board[x][i] = 7;
            if (board[x][i] == 6) return 0;
        }
    }
    return 0;
}
int col(int x, int y, int idx) {
    // 1:위 2:아래 3:위 채우기 4: 아래 채우기
    if (idx == 1) {
        int sum = 0;
        for (int i = x; i < n; i++) {
            if (board[i][y] == 0) sum++;
            if (board[i][y] == 6) return sum;
        }
        return sum;
    }
    if (idx == 2) {
        int sum = 0;
        for (int i = x; i >= 0; i--) {
            if (board[i][y] == 0) sum++;
            if (board[i][y] == 6) return sum;
        }
        return sum;
    }
    if (idx == 3) {
        for (int i = x; i < n; i++) {
            if (board[i][y] == 0) board[i][y] = 7;
            if (board[i][y] == 6) return 0;
        }
    }
    if (idx == 4) {
        for (int i = x; i >= 0; i--) {
            if (board[i][y] == 0) board[i][y] = 7;
            if (board[i][y] == 6) return 0;
        }
    }
    return 0;
}

int main() {
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        vector<int> v;
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            v.push_back(num);
        }
        board.push_back(v);
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) {
                int left = row(i, j, 1);
                int right = row(i, j, 2);
                if (left > right) row(i, j, 3);
                if (left < right) row(i, j, 4);
            }
            if (board[i][j] == 2) {
                int row_cnt = row(i, j, 1) + row(i, j, 2);
                int col_cnt = col(i, j, 1) + col(i, j, 2);
                if (row_cnt < col_cnt) {
                    col(i, j, 3);
                    col(i, j, 4);
                }
                if (row_cnt > col_cnt) {
                    row(i, j, 3);
                    row(i, j, 4);
                }
            }
            if (board[i][j] == 3) {
                int numarr[4];
                int first   = col(i, j, 1) + row(i, j, 2);      numarr[0] = first;
                int second  = col(i, j, 2) + row(i, j, 2);      numarr[1] = second;
                int third   = col(i, j, 2) + row(i, j, 1);      numarr[2] = third;
                int fourth  = col(i, j, 1) + row(i, j, 1);      numarr[3] = fourth;
                sort(numarr, numarr + 4);
                if (numarr[3] == first) {
                    col(i, j, 3);   row(i, j, 4);
                }
                if (numarr[3] == second) {
                    col(i, j, 4);   row(i, j, 4);
                }
                if (numarr[3] == third) {
                    col(i, j, 4);   row(i, j, 3);
                }
                if (numarr[3] == fourth) {
                    col(i, j, 3);   row(i, j, 3);
                }
            }
            if (board[i][j] == 4) {
                int numarr[4];
                int first   = col(i, j, 1)  + row(i, j, 1)  + row(i, j, 2); numarr[0] = first;
                int second  = col(i, j, 1)  + col(i, j, 2)  + row(i, j, 2); numarr[1] = second;
                int third   = col(i, j, 2)  + row(i, j, 1)  + row(i, j, 2); numarr[2] = third;
                int fourth  = col(i, j, 1)  + col(i, j, 2)  + row(i, j, 1); numarr[3] = fourth;
                sort(numarr, numarr + 4);
                if (numarr[3] == first) {
                    col(i, j, 3);   row(i, j, 3);   row(i, j, 4);
                }
                if (numarr[3] == second) {
                    col(i, j, 3);   col(i, j, 4);   row(i, j, 4);
                }
                if (numarr[3] == third) {
                    col(i, j, 4);   row(i, j, 3);   row(i, j, 4);
                }
                if (numarr[3] == fourth) {
                    col(i, j, 3);   col(i, j, 4);   row(i, j, 3);
                }
            }
            if (board[i][j] == 5) {
                row(i,j,3);
                row(i,j,4);
                col(i,j,3);
                col(i,j,4);
            }
        }
    }
    int cnt=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            if(board[i][j]==0) cnt++;
        }
    }
    cout<<cnt;
}