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

int calc(int x){
    if(x==1) return 0;
    if(dp[x]!=0) return dp[x];

    dp[x] = calc(x-1)+1;

    if(x%3==0) dp[x] = min(calc(x/3)+1, dp[x]);
    if(x%2==0) dp[x] = min(calc(x/2)+1, dp[x]);

    return dp[x];
}

int main(){
    quick_IO();
    int x;
    cin>>x;
    cout<<calc(x)<<"\n";

    return 0;
}