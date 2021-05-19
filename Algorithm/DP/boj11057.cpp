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

inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll dp[10][1001];

int main(){
    quick_IO();
    int n;
    cin>>n;
    for (int i = 0; i < 10; ++i) {
        dp[i][1] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for(int j = 0;j<10;j++){
            for (int k = 0; k <= j; ++k) {
                dp[j][i] += dp[k][i-1]%10007;
            }
        }
    }
    ll answer = 0;
    for (int i = 0; i < 10; ++i) {
        answer = (answer%10007 + dp[i][n]%10007)%10007;
    }
    cout<<answer<<"\n";
    return 0;
}