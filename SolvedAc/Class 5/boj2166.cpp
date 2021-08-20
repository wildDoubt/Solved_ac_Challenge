#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using p = pair<int, int>;
using ld = long double;
using ll = long long;
vector<p> arr;

int main() {
    int N;
    cin >> N;
    cout.precision(1);
    for (int i = 0, x, y; i < N; ++i) {
        cin >> x >> y;
        arr.emplace_back(x, y);
    }
    arr.emplace_back(*arr.begin());
    ll area1 = 0, area2 = 0;
    for (int i = 0; i < N; ++i) {
        area1 += ((ll)arr[i].first * arr[i + 1].second);
        area2 += ((ll)arr[i + 1].first * arr[i].second);
    }

    if (area2 > area1) swap(area1, area2);
    cout << fixed << (area1 - area2) / (ld) 2.0 << '\n';
    return 0;
}