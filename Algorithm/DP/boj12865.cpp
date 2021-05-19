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

int dp[105][100005];
vector<p> arr;

int main(){
    quick_IO();
    int n, k;
    cin>>n>>k;
    arr.emplace_back(0, 0);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin>>a>>b;
        arr.emplace_back(a, b);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if(j>=arr[i].first){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-arr[i].first] + arr[i].second);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][k]<<"\n";
    return 0;
}