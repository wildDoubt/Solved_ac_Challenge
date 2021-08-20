#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 0x66554433;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    Quick_IO();
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int pArr[N+1];
        int dp[N+1];
        fill(pArr, pArr+N+1, 0);
        fill(dp, dp+N+1, -INF);
        for (int i = 1, input; i <= N; ++i) {
            cin>>input;
            pArr[i] += pArr[i-1] + input;
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = i-1; j >=0 ; --j) {
                dp[i] = max(dp[i], pArr[i]-pArr[j]);
            }
        }
        cout<<*max_element(dp, dp+N+1)<<'\n';
    }

    return 0;
}