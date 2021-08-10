#include <iostream>
#include <algorithm>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool board[10][10];
int S[6] = {0, 5, 5, 5, 5, 5};
int answer = 26;

bool rangeCheck(int x, int y) {
    return x >= 0 && x <= 10 && y >= 0 && y <= 10;
}

int check(int x, int y, int size) {
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (!board[i][j]) return false;
        }
    }
    return true;
}

void restore(int x, int y, int size, bool isOne) {
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            board[i][j] = isOne;
        }
    }
}

void dfs(int x, int y, int counts) {
    if (x > 8 && y > 9) {
        answer = min(answer, counts);
        return;
    }
    if (answer <= counts) return;
    if (y > 9) {
        dfs(x + 1, 0, counts);
        return;
    }
    if (board[x][y]) {
        for (int i = 5; i >= 1; --i) {
            if (rangeCheck(x + i, y + i) && S[i] > 0 && check(x, y, i)) {
                S[i]--;
                restore(x, y, i, false);
                dfs(x, y + 1, counts + 1);
                S[i]++;
                restore(x, y, i, true);
            }
        }
    } else {
        dfs(x, y + 1, counts);
    }
}


int main() {
    Quick_IO();
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> board[i][j];
        }
    }
    dfs(0, 0, 0);
    if (answer > 25) {
        cout << "-1\n";
    } else {
        cout << answer << '\n';
    }

    return 0;
}