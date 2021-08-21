#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
const int MAX = 1 << 20;
const int MOD = 1000000007;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll tree[2 * MAX];

void update(int index) {
    if (index == 0) return;
    tree[index] = 1ll * tree[index * 2] * tree[index * 2 + 1] % MOD;
    update(index / 2);
}

ll calc(int L, int R, int nodeNum, int nodeL, int nodeR) {
    if (nodeR <= L || nodeL >= R) return 1ll;
    if (L <= nodeL && R >= nodeR) {
        return tree[nodeNum];
    }
    int mid = (nodeL + nodeR) / 2;
    return 1ll * calc(L, R, nodeNum * 2, nodeL, mid) * calc(L, R, nodeNum * 2 + 1, mid, nodeR) % MOD;
}

int main() {
    Quick_IO();
    int N, M, K;
    cin >> N >> M >> K;
    fill(tree, tree + 2 * MAX, 1);
    for (int i = 0; i < N; ++i) {
        ll input;
        cin >> input;
        tree[MAX + i] = input;
        update((MAX + i) / 2);
    }


    for (int i = 0, q, a, b; i < M + K; ++i) {
        cin >> q >> a >> b;
        if (q == 1) {
            tree[MAX + a - 1] = b;
            update((MAX + a - 1) / 2);
        } else {
            cout << calc(a - 1, b, 1, 0, MAX) << '\n';
        }
    }
    return 0;
}