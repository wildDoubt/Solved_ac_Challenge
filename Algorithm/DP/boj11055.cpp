// 8분 36초

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>

using namespace std;
using p = pair<int, int>;
using ll = long long;
const int MAX = 10e+6;
const int INF = 0x66554433;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int arr[1005];
int dp[1005];

int main(){
    Quick_IO();
    int N;
    cin>>N;
    for (int i = 0; i < N; ++i) {
        cin>>arr[i];
    }
    dp[0] = arr[0];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if(arr[j]<arr[i]){
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }else{
                dp[i] = max(dp[i], arr[i]);
            }
        }
    }
    cout<<*max_element(dp, dp+N)<<"\n";
    return 0;
}