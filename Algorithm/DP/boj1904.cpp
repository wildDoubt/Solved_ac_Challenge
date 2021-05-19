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

int dp[1000001];

int main(){
    quick_IO();
    int N;
    cin>>N;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3;i<=N;i++){
        dp[i] = (dp[i-2]%15746 + dp[i-1]%15746)%15746;
    }
    cout<<dp[N]<<"\n";
    return 0;
}