#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
using p = pair<int, int>;
using node = pair<p, bool>;
const int MAX = 1e3;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
bool board[MAX][MAX];
bool visited[2][MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    string input;
    for (int i = 0; i < N; ++i) {
        cin >> input;
        for (int j = 0; j < M; ++j) board[i][j] = input[j] - '0';
    }

    queue<node> q;

    q.push(node(p(0, 0), false));
    int level = 1;
    while (!q.empty()) {
        int size = (int) q.size();
        for (int i = 0; i < size; ++i) {
            auto[currPos, isBroken] = q.front();
            auto[currX, currY] = currPos;
            q.pop();
//            cout << currX << ' ' << currY << " : " << level << ", " << isBroken << '\n';
            if (currX == N - 1 && currY == M - 1) {
                cout << level << '\n';
                return 0;
            }
            for (int j = 0; j < 4; ++j) {
                int newX = currX + dx[j], newY = currY + dy[j];
                if (newX >= 0 && newX < N && newY >= 0 && newY < M) {
                    // 부수지 않았을 때 방문하지 않았으면 방문
                    // 전에 부쉈을 때 방문한 노드에 방문하지 않을 수도 있기 때문에
                    // 2개의 케이스로 나눠야 한다.
                    if (!visited[isBroken][newX][newY] && !board[newX][newY]) {
                        q.push(node(p(newX, newY), isBroken));
                        visited[isBroken][newX][newY] = true;
                    }
                    // 부쉈을 때 방문하지 않았으면 방문
                    // 이미 전에 부수고 방문했으면 이번에 방문하는 건 최단거리가 아니다.
                    if (!visited[isBroken][newX][newY] && !isBroken && board[newX][newY]) {
                        q.push(node(p(newX, newY), true));
                        visited[isBroken][newX][newY] = true;
                    }
                }
            }
        }
        level++;
    }
    cout << "-1\n";
    return 0;
}