#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>

using namespace std;
using p = pair<int, int>;
const int MAX = 1e3;

int N, M;
int board[MAX][MAX];
bool visited[MAX][MAX];
vector<p> wallPosition;
vector<p> roadPosition;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int parent[MAX * MAX];
int connected_path[MAX * MAX];

int find(int a) {
    if (parent[a] == a) return a;
    else {
        return parent[a] = find(parent[a]);
    }
}

void _union(int a, int b) {
    int x = find(a);
    int y = find(b);
    parent[y] = x;
}

void record_connected_path(p startPosition) {
    int ret = 0;
    auto[startX, startY] = startPosition;
    queue<p> q;
    q.push(startPosition);

    while (!q.empty()) {
        auto[currX, currY] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nextX = currX + dx[i], nextY = currY + dy[i];
            if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M
                && !visited[nextX][nextY]
                && board[nextX][nextY] == 0) {
                q.push(p(nextX, nextY));
                _union(startX * M + startY, nextX * M + nextY);
                visited[nextX][nextY] = true;
                ret++;
            }
        }
    }
    connected_path[startX * M + startY] = ret == 0 ? 1 : ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    memset(visited, false, sizeof(visited));

    cin >> N >> M;

    string input;
    for (int i = 0; i < N * M; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < N; ++i) {
        cin >> input;
        for (int j = 0; j < M; ++j) {
            if (input[j] == '1') {
                board[i][j] = 1;
                wallPosition.emplace_back(i, j);
            } else {
                roadPosition.emplace_back(i, j);
            }
        }
    }
    for (auto currPosition: roadPosition) {
        record_connected_path(currPosition);
    }

    for (auto currPosition: wallPosition) {
        auto[currX, currY] = currPosition;
        set<int> s;
        for (int i = 0; i < 4; ++i) {
            int nextX = currX + dx[i], nextY = currY + dy[i];
            if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
                s.insert(find(nextX * M + nextY));
            }
        }
        for (int i:s) {
            board[currX][currY] = (board[currX][currY] + connected_path[i]) % 10;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}