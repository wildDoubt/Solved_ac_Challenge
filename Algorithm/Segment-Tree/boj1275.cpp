#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
const int MAX = 1 << 20;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll tree[MAX * 2];

void update(int index) {
    if (index == 0) return;
    tree[index] = tree[index * 2] + tree[index * 2 + 1];
    update(index / 2);
}

ll calc(int nodeNum, int L, int R, int nodeL, int nodeR) {
    if (nodeR <= L || nodeL >= R) return 0ll;
    if (L <= nodeL && R >= nodeR) {
        return tree[nodeNum];
    }
    int mid = (nodeL+nodeR)/2;
    return calc(nodeNum*2, L, R, nodeL, mid) + calc(nodeNum*2+1, L, R, mid, nodeR);
}

int main() {
    Quick_IO();
    int N, Q;
    cin >> N >> Q;

    for (int i = 0, input; i < N; ++i) {
        cin >> input;
        tree[MAX + i] = input;
        update((MAX + i) / 2);
    }
    for (int i = 0, x, y, a, b; i < Q; ++i) {
        cin >> x >> y >> a >> b;
        if(x>y) swap(x, y);
        cout<<calc(1, x-1, y,0, MAX)<<'\n';
        tree[MAX+a-1] = b;
        update((MAX+a-1)/2);
    }
    return 0;
}