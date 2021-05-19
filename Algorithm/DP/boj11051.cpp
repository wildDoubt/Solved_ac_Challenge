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

int dp[1001][1001];

int calc(int a, int b){
    if(dp[a][b]!=0) return dp[a][b];
    if(b==a|| b==0) return dp[a][b] = 1;

    return dp[a][b] = (calc(a-1, b)%10007 + calc(a-1, b-1)%10007)%10007;
}

int main(){
    quick_IO();
    int n, k;
    cin>>n>>k;
    cout<<calc(n, k)<<"\n";
    return 0;
}