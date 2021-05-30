#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using p = pair<int, int>;

const int INF = 0x66554433;
const int MAX = 1e6 + 5;
const int MOD = 998244353;
int dp[MAX];
int arr[MAX];
int main() {
    int n;
    int ps = 1;
    cin >> n;
    // n까지의 약수개수
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j+=i) {
            arr[j]++;
        }
    }
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = (arr[i]+ps)%MOD;
        ps =(ps+dp[i])%MOD;
    }

    cout << dp[n] << " ";
    return 0;
}