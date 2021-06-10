#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int MOD = 1e9;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    Quick_IO();
    int N;
    cin >> N;
    int dp[N+1];
    int arr[21];
    memset(dp, 0, sizeof(dp));
    arr[0] = 1;
    for (int i = 1; i < 21; ++i) {
        arr[i] = arr[i-1]*2;
    }
    dp[0] = 1;
    for(auto x:arr){
        if(x<=N) {
            cout<<x<<" add"<<endl;
            for (int i = 1; i <= N; ++i) {
                if (i - x >= 0)
                    dp[i] = (dp[i] + dp[i - x]) % MOD;
            }
            for (int i = 0; i <= N; ++i) {
                cout<<dp[i]<<" ";
            }
            cout<<endl;
        }

    }
    cout<<dp[N]<<'\n';

    return 0;
}