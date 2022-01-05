#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct disjointSet {
    vector<int> parent, rank;

    disjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        rank.resize(n, 1);
    }

    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    void merge(int u, int v) {
        int x = find(u), y = find(v);

        if(x==y) return;
        if(rank[x] > rank[y]) swap(x, y);

        parent[x] = y;
        if(rank[x] == rank[y]) rank[y]++;
    }
};

struct edge {
    int dist;
    int u;
    int v;

    edge(int _dist, int _u, int _v) {
        dist = _dist;
        u = _u;
        v = _v;
    }
};

struct compare {
    bool operator()(edge a, edge b) {
        return a.dist > b.dist;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        int edgeNum = r * c - 1, currEdgeNum = 0, answer = 0;
        priority_queue<edge, vector<edge>, compare> edges;
        for (int i = 0; i < r; ++i) {
            for (int j = 0, input; j < c - 1; ++j) {
                cin >> input;
                int u = i * c + j;
                edges.push(edge(input, u, u + 1));
            }
        }

        for (int i = 0; i < r - 1; ++i) {
            for (int j = 0, input; j < c; ++j) {
                cin >> input;
                int u = i * c + j;
                edges.push(edge(input, u, u + c));
            }
        }

        disjointSet disjoint_set(r * c);
        while (currEdgeNum < edgeNum) {
            auto[dist, u, v] = edges.top();
            edges.pop();

            int x = disjoint_set.find(u), y = disjoint_set.find(v);
            if (x != y) {
                disjoint_set.merge(x, y);
                currEdgeNum++;
                answer += dist;
            }
        }
        cout << answer << '\n';
    }

    return 0;
}