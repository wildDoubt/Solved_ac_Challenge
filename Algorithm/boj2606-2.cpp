#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<int> adj[5051];
bool visited[101];

int dfs(int curr) {
    int totalSum = 0;
    for (auto x:adj[curr]) {
        if (!visited[x]) {
            visited[x] = true;
            totalSum += dfs(x) + 1;
        }
    }
    return totalSum;
}

int main() {
    Quick_IO();

    int V, E;
    int v1, v2;

    cin >> V >> E;

    fill(visited, visited + V + 1, false);

    for (int i = 0; i < E; ++i) {
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    cout << dfs(1) - 1 << '\n';


    return 0;
}