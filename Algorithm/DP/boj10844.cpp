#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
const int MOD = 1e9;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll dp[101][10];

int main() {
    Quick_IO();
    int N;
    cin >> N;
    for (int i = 1; i < 10; ++i) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][1];
            } else if (j == 1) {
                if(i==2){
                    dp[i][j] = dp[i - 1][2];
                }else{
                    dp[i][j] = (dp[i-1][2] + dp[i-1][0])%MOD;
                }
            } else if (j == 9) {
                dp[i][j] = dp[i - 1][8];
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }
    ll answer = 0;
    for (int i = 0; i < 10; ++i) {
        answer = (answer + dp[N][i]) % MOD;
    }

    cout << answer << '\n';
    return 0;
}