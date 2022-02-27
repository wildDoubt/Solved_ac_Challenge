#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N;
    ll maxWeight = LONG_LONG_MIN;
    cin >> N;
    vector<int> arr(N);
    for (int &rope: arr) {
        cin >> rope;
    }
    sort(arr.begin(), arr.end(), greater<>());
    for (int i = 0; i < N; ++i) {
        maxWeight = max(maxWeight, arr[i] * (long long)(i + 1));
    }

    cout << maxWeight << '\n';
    return 0;
}