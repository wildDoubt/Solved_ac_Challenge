#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using p = pair<int, int>;

const int INF = 0x66554433;
const int MAX = 3e5+5;

inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<p> adj[MAX];
int dist[MAX];
bool visited[MAX];
priority_queue<p, vector<p>, greater<>> pq;

int main(){
    quick_IO();
    int n, m;
    cin>>n>>m;
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin>>u>>v>>w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    cin>>u;

    return 0;
}