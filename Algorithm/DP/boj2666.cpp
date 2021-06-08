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

int dp[21][21][21];
int arr[21];
int N, a, b, n;

int calc(int i, int open1, int open2){
    if(i>=n) return 0;
    if(dp[i][open1][open2]!=-1) return dp[i][open1][open2];
    return dp[i][open1][open2] = min(
            calc(i+1, arr[i], open2) + abs(arr[i]-open1),
            calc(i+1, open1, arr[i]) + abs(arr[i]-open2)
            );
}

int main() {
    Quick_IO();
    cin >> N;
    cin >> a >> b;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }

    cout<<calc(0, a, b)<<endl;
    return 0;
}