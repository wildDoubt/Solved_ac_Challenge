// 방문한 곳은 visited로 다시 방문하지 않도록 처리해야 TLE가 안남.

#define LOCAL

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int board[505][505];
int dp[505][505];
bool visited[505][505];
int M, N;

int calc(int x, int y) {
    if (x >= 0 && x < M && y >= 0 && y < N) {
        if(visited[x][y]) return dp[x][y];

        if (dp[x][y] != 0)
            return dp[x][y];
        if (x == 0 && y == 0)
            return dp[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            if (board[x + dx[i]][y + dy[i]] > board[x][y]) {
                dp[x][y] += calc(x + dx[i], y + dy[i]);
                visited[x+dx[i]][y+dy[i]] = true;
            }
        }
        return dp[x][y];
    } else {
        return 0;
    }

}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> M >> N;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }
    // memset(dp, -1, sizeof(dp));
    cout << calc(M - 1, N - 1) << '\n';
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}