#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 1<<20;

int arr[MAX], n;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<int> mst[MAX * 2 + 5];

void build(int nodeNum, int L, int R) {
    if (L + 1 == R) {
        mst[nodeNum].push_back(arr[L]);
        return;
    }
    int mid = (L + R) / 2;
    build(nodeNum * 2, L, mid);
    build(nodeNum * 2 + 1, mid, R);
    mst[nodeNum].resize(mst[nodeNum * 2].size() + mst[nodeNum*2+1].size());
    merge(mst[nodeNum * 2].begin(), mst[nodeNum * 2].end(), mst[nodeNum * 2 + 1].begin(), mst[nodeNum * 2 + 1].end(),
          mst[nodeNum].begin());
}

int calc(int nodeNum, int L, int R, int nodeL, int nodeR, int k) {
    if (L >= nodeR || R <= nodeL) return 0;
    if (L <= nodeL && nodeR <= R) {
        return mst[nodeNum].end() - upper_bound(mst[nodeNum].begin(), mst[nodeNum].end(), k);
    }
    int mid = (nodeL + nodeR) / 2;
    return calc(nodeNum * 2, L, R, nodeL, mid, k) + calc(nodeNum * 2 + 1, L, R, mid, nodeR, k);
}

int main() {
    Quick_IO();
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    build(1, 0, n);
    int m;
    cin >> m;
    for (int i = 0, a, b, c; i < m; ++i) {
        cin >> a >> b >> c;
        cout<<calc(1, a - 1, b, 0, n, c)<<'\n';
    }

    return 0;
}