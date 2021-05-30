// dp

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

inline void quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    quick_IO();
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        int a_size = (int) a.size();
        int b_size = (int) b.size();
        int dp[a_size + 1][b_size + 1];
        int result = 0;
        for (int i = 0; i <= b_size; ++i) {
            dp[0][i] = 0;
        }
        for (int i = 0; i <= a_size; ++i) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= a_size; ++i) {
            for (int j = 0; j <= b_size; ++j) {
                if(i==0||j==0){
                    dp[i][j] = 0;
                }
                else if (a[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    result = max(result, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        cout << a_size+b_size-2*result<<"\n";

    }
    return 0;
}