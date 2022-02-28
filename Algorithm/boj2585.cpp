#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using p = pair<int, int>;
const int MAX = 1e3 + 5;

p coords[MAX];
bool visited[MAX];
int n, k;

int getDistance(p start, p end) {
    auto[x1, y1] = start;
    auto[x2, y2] = end;
    int xDistance = (x1 - x2) * (x1 - x2);
    int yDistance = (y1 - y2) * (y1 - y2);
    return xDistance + yDistance;
}

bool dfs(int currIndex, int currCount, const double &maxDistance) {
    if (currCount > k) return false;

    if (getDistance(coords[currIndex], coords[n + 1]) < maxDistance) {
        return true;
    }
    visited[currIndex] = true;
    for (int i = 1; i <= n + 1; ++i) {
        if (visited[i]) continue;
        int distance = getDistance(coords[currIndex], coords[i]);
        if (distance > maxDistance) continue;
        if (dfs(i, currCount + 1, maxDistance)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> k;
    coords[0] = {0, 0};
    for (int i = 1, x, y; i <= n; ++i) {
        cin >> x >> y;
        coords[i] = {x, y};
    }
    coords[n + 1] = {10000, 10000};
    int l = 0, r = 15000;
    int answer = INT32_MAX;
    while (l <= r) {
        int mid = (l + r) / 2;
        bool success = dfs(0, 0, mid * mid * 100);
        if (success) {
            answer = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
        memset(visited, false, sizeof(visited));
    }
    cout << answer << '\n';

    return 0;
}

