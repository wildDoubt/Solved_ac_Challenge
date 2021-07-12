#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>
#include <sstream>
#include <bitset>

using namespace std;
using p = pair<int, int>;
using ll = long long;
const int MAX = 10e+6;
const int INF = 0x66554433;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int dp[16];

int main() {
    Quick_IO();
    int N;
    cin >> N;
    vector<p> arr(N + 5);

    for (int i = 0; i < N; ++i) {
        int T, P;
        cin >> T >> P;
        arr[i] = p(T, P);
    }

    for (int i = 0; i < N; ++i) {
        if (i + arr[i].first <= N) {
            dp[i + arr[i].first] = max(dp[i + arr[i].first], dp[i] + arr[i].second);
        }
        dp[i + 1] = max(dp[i], dp[i + 1]);
    }
    cout << *max_element(dp, dp + N + 5);
    return 0;
}