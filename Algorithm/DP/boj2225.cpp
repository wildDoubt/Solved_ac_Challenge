#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>
#include <sstream>

using namespace std;
using p = pair<int, int>;
using ll = long long;
const int MAX = 10e+6;
const int INF = 0x66554433;
const int MOD = 1e9;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int dp[201][201];

int main() {
    Quick_IO();
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < 201; ++i) {
        dp[i][1] = 1;
    }
    for (int i = 0; i < 201; ++i) {
        for (int j = 1; j < 201; ++j) {
            // dp[i][j] = sum of (0..i = k 일 때 dp[i-k][j-1])
            for (int k = 0; k <= i; ++k) {
                dp[i][j] = (dp[i][j] + dp[i-k][j-1])%MOD;
            }
        }
    }
    cout << dp[N][K]%MOD << endl;

    return 0;
}