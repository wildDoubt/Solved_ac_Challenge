#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 1 << 17;
const int LIMIT = 1e9;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int arr[MAX];
vector<int> mst[MAX * 2 + 5];

void build(int nodeNum, int L, int R) {
    if (L + 1 == R) {
        mst[nodeNum].push_back(arr[L]);
        return;
    }
    int mid = (L + R) / 2;
    build(nodeNum * 2, L, mid);
    build(nodeNum * 2 + 1, mid, R);
    mst[nodeNum].resize(mst[nodeNum * 2].size() + mst[nodeNum * 2 + 1].size());
    merge(mst[nodeNum * 2].begin(), mst[nodeNum * 2].end(), mst[nodeNum * 2 + 1].begin(), mst[nodeNum * 2 + 1].end(),
          mst[nodeNum].begin());
}

int calc(int nodeNum, int L, int R, int nodeL, int nodeR, int k) {
    if (L >= nodeR || R <= nodeL) return 0;
    if (L <= nodeL && nodeR <= R) {
        return upper_bound(mst[nodeNum].begin(), mst[nodeNum].end(), k) - mst[nodeNum].begin();
    }
    int mid = (nodeL + nodeR) / 2;
    return calc(nodeNum * 2, L, R, nodeL, mid, k) + calc(nodeNum * 2 + 1, L, R, mid, nodeR, k);
}

int main() {
    Quick_IO();
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> arr[i];

    build(1, 0, N);

    for (int i = 0; i < M; ++i) {
        int left, right, K;
        cin >> left >> right >> K;
        int l = -LIMIT, r = LIMIT;
        int answer = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            int result = calc(1, left - 1, right, 0, N, mid);

            if (result >= K) {
                answer = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << answer << '\n';
    }


    return 0;
}