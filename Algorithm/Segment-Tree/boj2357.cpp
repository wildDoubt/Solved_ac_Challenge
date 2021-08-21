#include <iostream>
#include <algorithm>

using namespace std;
using p = pair<int, int>;
const int MAX = 1 << 20;
const int INF = 2e9;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

p tree[2 * MAX];

void update(int node) {
    if (node == 0) return;
    tree[node].first = min(tree[node * 2].first, tree[node * 2 + 1].first);
    tree[node].second = max(tree[node * 2].second, tree[node * 2 + 1].second);
    update(node / 2);
}


p calc(int nodeNum, int nodeL, int nodeR, int L, int R) {
    if (nodeR <= L || nodeL >= R) return p(INF, 0);
    if (L <= nodeL && R >= nodeR) {
        return tree[nodeNum];
    }
    int mid = (nodeL + nodeR) / 2;
    p left = calc(nodeNum * 2, nodeL, mid, L, R);
    p right = calc(nodeNum * 2 + 1, mid, nodeR, L, R);
    return p(min(left.first, right.first), max(left.second, right.second));
}


int main() {
    Quick_IO();
    int N, M;
    cin >> N >> M;

    fill(tree, tree + 2 * MAX, p(INF, 0));

    for (int i = 0, input; i < N; ++i) {
        cin >> input;
        tree[MAX + i] = p(input, input);
        update((MAX + i) / 2);
    }

    for (int i = 0, l, r; i < M; ++i) {
        cin >> l >> r;
        p answer = calc(1, 0, MAX, l-1, r);
        cout << answer.first<<" "<<answer.second << '\n';
    }
    return 0;
}