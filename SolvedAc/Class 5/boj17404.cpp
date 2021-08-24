#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 1e3 + 5;
const int INF = 0x66554433;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int dp[3][MAX][3];
int map[MAX][3];

int main() {
    Quick_IO();
    int N;
    cin >> N;
    memset(dp, INF, sizeof(dp));
    for (int i = 1, R, G, B; i <= N; ++i) {
        cin >> R >> G >> B;
        map[i][0] = R, map[i][1] = G, map[i][2] = B;
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            dp[i][0][j] = 0;
        }
    }
    dp[0][1][0] = map[1][0];
    dp[1][1][1] = map[1][1];
    dp[2][1][2] = map[1][2];

    for (int k = 0; k < 3; ++k) {
        for (int i = 2; i <= N; ++i) {
            for (int j = 0; j < 3; ++j) {
                dp[k][i][j] = min(dp[k][i - 1][(j + 1) % 3], dp[k][i - 1][(j + 2) % 3]) + map[i][j];
            }
        }
    }

    cout << min({dp[0][N][1], dp[0][N][2],
                 dp[1][N][2], dp[1][N][0],
                 dp[2][N][0], dp[2][N][1]});

    return 0;
}