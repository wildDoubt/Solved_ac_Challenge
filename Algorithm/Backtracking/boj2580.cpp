#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using p = pair<int, int>;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int board[9][9];
vector<p> arr;

bool check(int x, int y, int value) {
    for (int i = 0; i < 9; ++i) {
        if (y == i) continue;
        if (board[x][i] == value) return false;
    }
    for (int i = 0; i < 9; ++i) {
        if (x == i) continue;
        if (board[i][y] == value) return false;
    }

    for (int i = (x / 3) * 3; i < (x / 3) * 3 + 3; ++i) {
        for (int j = (y / 3) * 3; j < (y / 3) * 3 + 3; ++j) {
            if (x == i && y == j) continue;
            if (board[i][j] == value) return false;
        }
    }
    return true;
}

void dfs(int index) {
    int x = arr[index].first;
    int y = arr[index].second;
    if (index == (int) arr.size()) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }
    for (int i = 1; i <= 9; ++i) {
        if (check(x, y, i)) {
            board[x][y] = i;
            dfs(index + 1);
            board[x][y] = 0;
        }
    }
}

int main() {
    Quick_IO();

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                arr.emplace_back(i, j);
            }
        }
    }
    dfs(0);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}