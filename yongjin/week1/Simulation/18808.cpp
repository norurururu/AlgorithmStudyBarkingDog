#include <iostream>
#include <vector>
using namespace std;

int N, M, K, R, C;
vector<vector<int>> notebook;

vector<vector<int>> rotate(const vector<vector<int>>& sticker) {
    int row = sticker.size();
    int col = sticker[0].size();
    vector<vector<int>> rotated(col, vector<int>(row));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            rotated[j][row - 1 - i] = sticker[i][j];
        }
    }
    return rotated;
}

bool can_attach(int x, int y, const vector<vector<int>>& sticker) {
    for (int i = 0; i < sticker.size(); ++i) {
        for (int j = 0; j < sticker[i].size(); ++j) {
            if (sticker[i][j] && notebook[x + i][y + j]) return false;
        }
    }
    return true;
}

void attach(int x, int y, const vector<vector<int>>& sticker) {
    for (int i = 0; i < sticker.size(); ++i) {
        for (int j = 0; j < sticker[i].size(); ++j) {
            if (sticker[i][j]) notebook[x + i][y + j] = 1;
        }
    }
}

int main() {
    cin >> N >> M >> K;
    notebook.assign(N, vector<int>(M, 0));
    while (K--) {
        cin >> R >> C;
        vector<vector<int>> sticker(R, vector<int>(C));
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                cin >> sticker[i][j];
        
        bool attached = false;
        for (int rotation = 0; rotation < 4; ++rotation) {
            if (attached) break;
            for (int i = 0; i <= N - sticker.size(); ++i) {
                if (attached) break;
                for (int j = 0; j <= M - sticker[0].size(); ++j) {
                    if (can_attach(i, j, sticker)) {
                        attach(i, j, sticker);
                        attached = true;
                        break;
                    }
                }
            }
            if (!attached) sticker = rotate(sticker);
        }
    }

    int count = 0;
    for (auto& row : notebook) {
        for (int cell : row) {
            if (cell) ++count;
        }
    }
    cout << count << endl;
    return 0;
}
