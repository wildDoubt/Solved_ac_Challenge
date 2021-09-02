#include <iostream>

using namespace std;

int dp[50001];
bool isSquare[50001];

int solve(int num, int depth) {
    int &ret = dp[num];
    if (depth > 4) return 4;
    if (ret != -1) return ret;
    if (isSquare[num]) return ret = 1;
    ret = 4;
    for (int i = 1; i * i < num; ++i) {
        ret = min(ret, solve(num - i * i, depth + 1) + 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;

    fill(dp, dp + n + 1, -1);
    for (int i = 1; i * i <= n; ++i) isSquare[i * i] = true, dp[i*i] = 1;

    cout << solve(n, 1) << '\n';
    return 0;
}