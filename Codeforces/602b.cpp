#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100000;
int arr[MAX + 1];
int dp[MAX + 1];

inline void quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    quick_IO();
    int n;
    int i;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int lo = 0;
    int hi = 1;
    int minValue = arr[0];
    int maxValue = arr[0];
    int lastMinIndex = 0;
    int lastMaxIndex = 0;
    dp[0] = hi - lo;

    for (; hi < n; hi++) {
        if (abs(minValue - arr[hi]) < 2 && abs(maxValue - arr[hi]) < 2) {
            dp[hi] = hi - lo + 1;
            if (arr[hi] <= minValue) {
                minValue = arr[hi];
                lastMinIndex = hi;
            }
            if (arr[hi] >= maxValue) {
                maxValue = arr[hi];
                lastMaxIndex = hi;
            }
        } else {
            // lo를 skip 처리할 수 있는 상황인 경우
            if (minValue != maxValue) {
                if (maxValue - 2 == arr[hi]) {
                    lo = lastMaxIndex + 1;
                    lastMaxIndex = lastMinIndex;
                    lastMinIndex = hi;
                    maxValue = minValue;
                    minValue = arr[hi];
                }
                if (minValue + 2 == arr[hi]) {
                    lo = lastMinIndex + 1;
                    lastMinIndex = lastMaxIndex;
                    lastMaxIndex = hi;
                    minValue = maxValue;
                    maxValue = arr[hi];
                }
                dp[hi] = hi - lo + 1;
                continue;
            }
            // hi부터 새로 카운트를 시작하는 경우
            minValue = arr[hi];
            maxValue = arr[hi];
            lastMaxIndex = hi;
            lastMinIndex = hi;
            lo = hi;
            dp[hi] = hi - lo + 1;
        }
    }
//    for (i = 0; i < n; i++) cout << dp[i] << " ";
    cout<<*max_element(dp, dp+n);
    cout << endl;
    return 0;
}