#include <iostream>
#include <algorithm>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int dp[1001];
int times[1001];
vector<int> parents[1001];

int calc(int target) {
    int &ret = dp[target];
    if (ret != -1) {
        return ret;
    }
    int result = times[target];
    int maxValue = 0;
    for (auto parent:parents[target]) {
        maxValue = max(maxValue, calc(parent));
    }
    return ret = result + maxValue;
}

int main() {
    Quick_IO();
    int T;
    cin >> T;

    while (T--) {
        for (auto &parent : parents) {
            parent.clear();
        }

        int N, K, W;

        cin >> N >> K;
        fill(dp + 1, dp + N + 1, -1);
        for (int i = 1; i <= N; ++i) {
            cin >> times[i];
        }
        for (int i = 0, x, y; i < K; ++i) {
            cin >> x >> y;
            parents[y].push_back(x);
        }
        cin >> W;
        cout << calc(W) << '\n';

    }

    return 0;
}