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

int arr[101];
int N, K;
int dp[10001];

int main() {
    Quick_IO();
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    dp[0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= K; ++j) {
            if(j-arr[i]>=0)
                dp[j] += dp[j-arr[i]];
        }
    }
    cout << dp[K] << endl;

    return 0;
}