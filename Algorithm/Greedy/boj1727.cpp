#include <iostream>

using namespace std;
const int MAX = 1e3 + 5;

int dp[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int man_n, woman_n;
    cin >> man_n >> woman_n;
    int men[man_n], women[woman_n];

    for (int &input:men) cin >> input;
    for (int &input:women) cin >> input;
    sort(men, men + man_n);
    sort(women, women + woman_n);

    for (int i = 1; i <= man_n; ++i) {
        for (int j = 1; j <= woman_n; ++j) {
            dp[i][j] = dp[i - 1][j - 1] + abs(men[i - 1] - women[j - 1]);
            if (i > j) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            if (i < j) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }
    }

    cout << dp[man_n][woman_n] << '\n';

    return 0;
}