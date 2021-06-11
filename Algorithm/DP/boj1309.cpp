#include <iostream>
#include <algorithm>

using namespace std;
const int MOD = 9901;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    Quick_IO();
    int N;
    cin>>N;
    int dp[N][3];
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = 1;
    for (int i = 1; i < N; ++i) {
        dp[i][0] = (dp[i-1][1] + dp[i-1][2])%MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2])%MOD;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])%MOD;
    }
    cout<<(dp[N-1][0]+dp[N-1][1]+dp[N-1][2])%MOD<<endl;
    return 0;
}