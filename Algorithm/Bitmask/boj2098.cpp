#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int INF = 1e9 + 5;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int N;
int adj[16][16];
int dp[16][1 << 16];

int calc(int curr, int visited) {
    int &ret = dp[curr][visited];
    if (ret != -1) return ret;
    if (visited == (1 << N) - 1) {
        if (adj[curr][0] != 0) return adj[curr][0];
        else return INF;
    }
    ret = INF;
    for (int i = 0; i < N; ++i) {
        if (visited & (1 << i) || adj[curr][i] == 0) continue;

        ret = min(ret, calc(i, visited | (1 << i)) + adj[curr][i]);
    }
    return ret;
}

int main() {
    Quick_IO();

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> adj[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << calc(0, 1) << '\n';

    return 0;
}