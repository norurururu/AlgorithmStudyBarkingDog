#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int board[8][8];
int meet[8][8];
int dx[4]{1, -1, 0, 0};
int dy[4]{0, 0, -1, 1};

int n, m;
queue<pair<int, int>> q;

void bfs(int i, int j) {
    q.push(make_pair(i, j));
    meet[i][j] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            if (board[nx][ny] != 1 && meet[nx][ny] != 1) {
                board[nx][ny] = 2;
                meet[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}
int cntZero(){
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(board[i][j]==0) cnt++;
        }
    }
}

int main() {
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            board[i][j] = num;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != 0) {
                bfs(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 2) {
                bfs(i, j);
            }
        }
    }
}