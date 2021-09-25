#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
const int MAX = 1 << 18;
const int MOD = 1'000'000'007;

ll tree[MAX * 2];
int tree1[MAX * 2];

void update(int index) {
    if (index <= 1) return;
    tree[index] = tree[index * 2] + tree[index * 2 + 1];
    update(index / 2);
}

void update1(int index) {
    if (index <= 1) return;
    tree1[index] = tree1[index * 2] + tree1[index * 2 + 1];
    update1(index / 2);
}

ll query(int num, int L, int R, int l, int r) {
    if (L >= r || R <= l) return 0ll;
    if (l >= L && r <= R) return tree[num];
    int mid = (l + r) / 2;
    return query(num * 2, L, R, l, mid) + query(num * 2 + 1, L, R, mid, r);
}

int query1(int num, int L, int R, int l, int r) {
    if (L >= r || R <= l) return 0;
    if (l >= L && r <= R) return tree1[num];
    int mid = (l + r) / 2;
    return query1(num * 2, L, R, l, mid) + query1(num * 2 + 1, L, R, mid, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int N;
    ll answer = 1;
    cin >> N;
    int arr[N];
    for (int i = 0, input; i < N; ++i) {
        cin >> input;
        arr[i] = input;
    }

    tree[MAX + arr[0]] = arr[0];
    tree1[(MAX + arr[0])] = 1;
    update1((MAX + arr[0]) / 2);
    update((MAX + arr[0]) / 2);
    for (int i = 1; i < N; ++i) {
        ll low = query1(1, 0, arr[i], 0, MAX);
        ll hi = query1(1, arr[i] + 1, MAX, 0, MAX);
        ll temp1 = (low * arr[i] - query(1, 0, arr[i], 0, MAX)) % MOD;
        ll temp2 = (query(1, arr[i] + 1, MAX, 0, MAX) - hi * arr[i]) % MOD;

        ll result = (temp1 + temp2) % MOD;
        answer = answer * result;
        answer = answer % MOD;
//        cout << low << ' ' << hi << '\n';
//        cout << temp1 << ' ' << temp2 << '\n';
        tree[MAX + arr[i]] += arr[i];
        tree1[MAX + arr[i]]++;
        update((MAX + arr[i]) / 2);
        update1((MAX + arr[i]) / 2);
    }
    cout << answer << '\n';
    return 0;
}