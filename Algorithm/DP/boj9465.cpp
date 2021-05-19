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

int arr[2][100000];
int dp[2][100000];

int main(){
    quick_IO();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i = 0;i<n;i++){
            cin>>arr[0][i];
        }
        for(int i = 0;i<n;i++){
            cin>>arr[1][i];
        }
        dp[0][0] = arr[0][0];
        dp[0][1] = arr[1][0] + arr[0][1];
        dp[1][0] = arr[1][0];
        dp[1][1] = arr[0][0] + arr[1][1];
        for(int i = 2;i<n;i++){
            int temp = max(dp[0][i-2], dp[1][i-2]); // i - 2 중 가장 큰 걸 가져와야한다.
            dp[0][i] = max(temp, dp[1][i-1]) + arr[0][i];
            dp[1][i] = max(temp, dp[0][i-1]) + arr[1][i];
        }
        cout<<max(dp[0][n-1], dp[1][n-1])<<"\n";
    }
    return 0;
}