#include <iostream>

using namespace std;
const int MAX = 1e4+5;

int arr[MAX];
int dp[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N;
    cin>>N;
    for (int i = 1; i <= N; ++i) {
        cin>>arr[i];
        dp[i] = arr[i];
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = i-1; j >= 1; j--) {
            dp[i] = max(dp[i], dp[i-j] + arr[j]);
        }
    }

    cout<<dp[N]<<'\n';

    return 0;
}