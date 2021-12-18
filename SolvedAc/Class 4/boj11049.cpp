#include <iostream>

using namespace std;
using p = pair<int, int>;
const int MAX = 500;

int dp[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N;
    cin >> N;
    p arr[N];

    for (int i = 0, r, c; i < N; ++i) {
        cin >> r >> c;
        arr[i] = p(r, c);
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 0; i + j < N; ++j) {
            dp[j][i+j] = INT32_MAX;
            for (int k = j; k <= i + j; ++k) {
                dp[j][i+j] = min(dp[j][i + j], dp[j][k] + dp[k+1][i+j] + arr[j].first * arr[k].second * arr[i+j].second);
            }
        }
    }

    cout<<dp[0][N-1]<<'\n';

    return 0;
}