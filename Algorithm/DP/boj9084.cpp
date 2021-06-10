#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>
#include <sstream>
#include <cstring>

using namespace std;
using p = pair<int, int>;
using ll = long long;
const int MAX = 10e+6;
const int INF = 0x66554433;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Quick_IO();
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int arr[N];
        for (int i = 0; i < N; ++i) {
            cin>>arr[i];
        }
        int M;
        cin>>M;
        int dp[M+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(auto x:arr){
            for (int i = 1; i <= M; ++i) {
                if(i-x>=0)
                    dp[i] += dp[i-x];
            }
        }
//        for (int i = 1; i <= M; ++i) {
//            cout<<dp[i]<<" ";
//        }
        cout<<dp[M]<<'\n';
    }

    return 0;
}