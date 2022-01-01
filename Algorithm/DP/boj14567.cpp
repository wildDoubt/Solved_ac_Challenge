#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e3+5;

vector<int> prerequisite[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N, M;
    cin>>N>>M;
    int dp[N + 1];

    fill(dp, dp+N+1, 1);

    for (int i = 0, a, b; i < M; ++i) {
        cin>>a>>b;
        prerequisite[b].push_back(a);
    }

    for (int i = 1; i <= N; ++i) {
        if(!prerequisite[i].empty()){
            int maxValue = INT32_MIN;
            for(int prev: prerequisite[i]){
                maxValue = max(maxValue, dp[prev]);
            }
            dp[i] += maxValue;
        }
    }
    for (int i = 1; i <= N; ++i) {
        cout<<dp[i]<<' ';
    }
    cout<<'\n';
    return 0;
}