#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {-1, 1, 0, 0};

bool used[26];
char board[20][20];
bool visited[20][20];
int R, C;
int answer = 1;

void dfs(int x, int y, int distance) {
    answer = max(answer, distance);
    visited[x][y] = true;
    used[board[x][y]-'A'] = true;
    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX >= 0 && newX < R &&
            newY >= 0 && newY < C &&
            !visited[newX][newY] &&
            !used[board[newX][newY]-'A']) {
            dfs(newX, newY, distance + 1);
        }
    }
    visited[x][y] = false;
    used[board[x][y]-'A'] = false;
}

int main() {
    Quick_IO();

    cin >> R >> C;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> board[i][j];
        }
    }

    used[board[0][0]-'A'] = true;
    visited[0][0] = true;

    dfs(0, 0, 1);

    cout << answer << '\n';

    return 0;
}