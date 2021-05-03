#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

const int MAX = 10e+6;
const int INF = 0x66554433;

int dp[MAX+1];
int arr[MAX+1];
inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    Quick_IO();
    int n;
    cin>>n;
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
    }
    for (int i = 1; i <= n; ++i) {
        // dp[i]는 i번째 수를 포함할 때 최대 합을 의미한다.
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
    }
    cout<<*max_element(dp+1, dp+n+1)<<"\n";
    return 0;
}