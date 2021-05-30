// https://codeforces.com/problemset/problem/1373/D

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
const int MIN = -2100000000;
int arr[200001];
int subArr[100001];

int n;

ll solve() {
    ll dp[100001];
    dp[0] = subArr[0];
    ll maxValue = dp[0];
    for(int i = 1;i<n/2;i++){
        dp[i] = max(dp[i-1], 0ll) + subArr[i];
        maxValue = max(dp[i], maxValue);
    }
    return maxValue;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    int i, j;
    cin >> t;
    while (t--) {
        ll answer = 0;
        ll temp = 0;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> arr[i];
            if (i % 2 == 0) temp += arr[i];
        }
        for (i = 0; i < n/2; i ++) {
            subArr[i] = arr[i*2+1] - arr[i*2];
        }
//        for(i=0;i<n/2;i++){
//            cout<<subArr[i]<<" ";
//        }
//        cout<<endl;
        answer = max(temp, temp + solve());

        fill(subArr, subArr + n/2, 0);
        for (i = 0; i < n / 2; i++) {
            if (n%2==0 && i == n / 2 - 1) continue;
            subArr[i] = arr[i*2+1] - arr[(i+1)*2];
        }
//        for(i=0;i<n/2;i++){
//            cout<<subArr[i]<<" ";
//        }
//        cout<<endl;

        cout<<max(answer, temp + solve()) << "\n";
        fill(subArr, subArr + n / 2, 0);
    }

}