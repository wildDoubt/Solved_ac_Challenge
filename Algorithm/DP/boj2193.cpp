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

ll dp[2][91];

int main(){
    quick_IO();
    int N;
    cin>>N;
    dp[0][1] = 0;
    dp[1][1] = 1;
    dp[0][2] = 1;
    dp[1][2] = 0;
    // 피보나치로도 풀 수 있음.
    for(int i = 3;i<=N;i++){
        dp[0][i] = dp[0][i-1] + dp[1][i-1];
        dp[1][i] = dp[1][i-2] = dp[0][i-1];
    }
    cout<<dp[0][N] + dp[1][N]<<"\n";
    return 0;
}