#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using p = pair<int, int>;
const int MAX = 10e+5;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int energy[MAX + 1];
vector<p> adj[MAX + 1];
int answer[MAX + 1];
bool visited[MAX + 1];

vector<p> dfs(int prev, int curr) {
    visited[curr] = true;
    vector<p> temp;
    temp.emplace_back(curr, energy[curr]);
    for (auto x: adj[curr]) {
        if (!visited[x.first]) {
            for (auto s: dfs(curr, x.first)) {
                if (s.second - x.second < 0) {
                    answer[s.first] = x.first;
                } else {
                    temp.emplace_back(s.first, s.second - x.second);
                }
            }
        }
    }
    return temp;
}

int main() {
    Quick_IO();
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> energy[i];
    }
    int a, b, c;
    for (int i = 0; i < N - 1; ++i) {
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    fill(answer + 1, answer + N + 1, 1);
    dfs(0, 1);

    for (int i = 1; i <= N; ++i) {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}