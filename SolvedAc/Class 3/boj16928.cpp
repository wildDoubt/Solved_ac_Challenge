#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
using p = pair<int, int>;

const int INF = 987654321;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int moves[101];
bool visited[101];

int bfs(int initialPosition) {
    queue<p> q;
    q.push({initialPosition, 0});
    int answer = INF;
    while (!q.empty()) {
        auto[currPosition, level] = q.front();
        q.pop();
        if (currPosition == 100) {
            return level;
        }

        for (int i = 1; i <= 6; ++i) {
            if (!visited[currPosition + i]&&currPosition + i <= 100) {
                q.push({moves[currPosition + i], level + 1});
                visited[currPosition + i] = true;
            }
        }
    }
    return answer;
}

int main() {
    Quick_IO();
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= 100; ++i) moves[i] = i;
    for (int i = 0, a, b; i < N + M; ++i) {
        cin >> a >> b;
        moves[a] = b;
    }
    cout << bfs(1) << '\n';

    return 0;
}