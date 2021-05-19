#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int INF = 10001;

inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int arr[101];
int dp[10001];
int N, K;


int main(){
    quick_IO();
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        cin>>arr[i];
    }
    fill(dp+1, dp + K + 1, INF);

    for(int i = 1;i<=N;i++){
        for(int j = arr[i];j<=K;j++){
            dp[j] = min(dp[j], dp[j-arr[i]]+1);
        }
    }

    if(dp[K] != INF) cout << dp[K] << "\n";
    else cout<<-1<<"\n";
    return 0;
}