#include <iostream>

using namespace std;
const int MAX = 100;

int dp[MAX][MAX * MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    int A[N], C[N], maxValue = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
        maxValue += C[i];
    }
    for (int i = C[0]; i <=maxValue; ++i) dp[0][i] = A[0];
    // dp[n][c]
    // dp는 n번째 가방에서 c만큼의 cost를 가지고 있을 때 정리할 수 있는 최대 바이트 수를 저장
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j <= maxValue; ++j) {
            if (j >= C[i]) {
                // 현재 앱을 넣을 수 있는 경우
                // 이전 상태의 최대값을 선택해야 하는데 j - C[i]가 이전 상태의 최대값이므로
                // 넣었을 때의 값: dp[i - 1][j - C[i]] + A[i]
                // 안 넣었을 때의 값: dp[i-1][j]
                // 둘 중 큰 값을 선택함.
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - C[i]] + A[i]);
            } else {
                // 못 넣는 경우는 이전 상태의 값과 똑같다.
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (int i = 0; i <= maxValue; ++i) {
        if(dp[N-1][i]>=M){
            cout<<i<<'\n';
            break;
        }
    }
    return 0;
}