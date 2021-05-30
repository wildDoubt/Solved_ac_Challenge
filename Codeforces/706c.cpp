#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;

const int MAX = 100000;
ll cost[MAX + 1];
string strings[MAX + 1];
string rStrings[MAX + 1];
ll DP[MAX + 1];
ll rDP[MAX + 1];
int n;

inline void quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool isSort(string a, string b) {
    if (a.compare(b) <= 0) return true;
    return false;
}

int main() {
    quick_IO();
    int i;
    cin >> n;
    fill(DP, DP + n + 1, 10e+15);
    fill(rDP, rDP + n + 1, 10e+15);
    for (i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    for (i = 1; i <= n; i++) {
        cin >> strings[i];
        rStrings[i] = string(strings[i].rbegin(), strings[i].rend());
    }
    DP[1] = 0;
    rDP[1] = cost[1];
    for (i = 2; i <= n; i++) {
        if (DP[i - 1] != -1 && (isSort(strings[i - 1], strings[i]))) {
            DP[i] = min(DP[i], DP[i - 1]);
        }
        if (rDP[i - 1] != -1 && (isSort(rStrings[i - 1], strings[i]))) {
            DP[i] = min(DP[i], rDP[i - 1]);
        }
        if (DP[i] == 10e+15) DP[i] = -1;
        if (DP[i - 1] != -1 && (isSort(strings[i - 1], rStrings[i]))) {
            rDP[i] = min(rDP[i], DP[i - 1] + cost[i]);
        }
        if (rDP[i - 1] != -1 && (isSort(rStrings[i - 1], rStrings[i]))) {
            rDP[i] = min(rDP[i], rDP[i - 1] + cost[i]);
        }
        if (rDP[i] == 10e+15) rDP[i] = -1;
    }
    if (min(DP[n], rDP[n]) != -1) {
        cout << min(DP[n], rDP[n]);
    }
    else {
        if (DP[n] == -1) cout << rDP[n];
        else if (rDP[n] == -1) cout << DP[n];
        else cout << -1;
    }
    cout << "\n";
    return 0;
}