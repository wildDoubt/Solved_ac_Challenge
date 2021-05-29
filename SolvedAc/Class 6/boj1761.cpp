// 다익스트라로 최단거리 계산 후 무식하게 LCA를 찾아서 TLE
// 트리에서 두 정점 사이의 경로는 유일하기 때문에
// DFS or BFS를 사용해서 거리를 구하면 시간 복잡도를 개선할 수 있다.
// 이후 LCA를 찾는 과정을 O(logN)으로 줄이면 통과.

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>

using namespace std;
using p = pair<int, int>;
using ll = long long;
const int MAX = 4e4 + 4;
const int INF = 0x66554433;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<p> adj[MAX];
bool visited[MAX];
int parent[MAX];

int main() {
    Quick_IO();
    int N, M;
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    vector<p> dist(MAX, p(INF, 0));  // dist, depth
    dist[1] = p(0, 1);
    queue<int> q;
    q.push(1);
    int depth = 0;
    visited[1] = true;
    while (!q.empty()) {
        int size = (int) q.size();
//        cout<<"==="<<depth<<"===\n";
        for (int i = 0; i < size; ++i) {
            int curr = q.front();
            dist[curr].second = depth;
//            cout<<curr<<" "<<dist[curr].first<<endl;
            for (auto x:adj[curr]) {
                if (!visited[x.first]) {
                    parent[x.first] = curr;
                    dist[x.first].first = x.second + dist[curr].first;
                    q.push(x.first);
                    visited[x.first] = true;
                }
            }
            q.pop();
        }
        depth++;
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        int answer = dist[u].first + dist[v].first;
        int u_depth = dist[u].second;
        int v_depth = dist[v].second;
        while (u_depth > v_depth) {
            u = parent[u];
            u_depth = dist[u].second;
        }
        while (v_depth > u_depth) {
            v = parent[v];
            v_depth = dist[v].second;
        }
        while (u != v) {
            u = parent[u];
            v = parent[v];
        }
        cout << answer - dist[u].first*2 << "\n";
        // 이 시점에서의 u는 LCA 노드
        // dist[u].first에서 *2를 한 값을 뺴줘야 함.
        // parent가 1이면 dist[u] + dist[v] 출력
        // parent가 1이 아닌 k면 dist[u] + dist[v] - dist[k] 출력
    }
    return 0;
}