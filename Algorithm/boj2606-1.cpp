#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 105;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int parent[MAX];

int find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    if (x == y) return;
    if (x >= y) {
        swap(x, y);
    }
    parent[y] = x;
}

int main() {
    Quick_IO();

    int V, E;
    int v1, v2;
    int answer = 0;

    cin >> V >> E;

    for (int i = 0; i < MAX; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < E; ++i) {
        cin >> v1 >> v2;
        merge(v1, v2);
    }

    for (int i = 1; i <= V; ++i) {
        if (find(i) == 1) answer++;
    }

    cout << answer - 1 << '\n';
    return 0;
}