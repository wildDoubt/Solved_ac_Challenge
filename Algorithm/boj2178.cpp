#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
using p = pair<int, int>;
const int MAX = 1e2 + 6;
const int INF = 0x66554433;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool arr[MAX][MAX];
bool visited[MAX][MAX];

int main() {
    Quick_IO();
    int N, M, answer = INF;
    int level = 1;
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        string a;
        cin >> a;
        for (int j = 0; j < (int) a.size(); ++j) {
            arr[i][j] = a[j] - '0';
        }
    }

    queue<p> q;
    q.push(p(0, 0));

    while (!q.empty()) {
        int size = (int) q.size();
        for (int i = 0; i < size; ++i) {
            auto [currX, currY] = q.front();
            q.pop();

            if (currX == N - 1 && currY == M - 1) {
                answer = min(answer, level);
            }

            for (int j = 0; j < 4; ++j) {
                int newX = currX + dx[j];
                int newY = currY + dy[j];

                if (!visited[newX][newY]
                    && (newX >= 0 && newX < N)
                    && (newY >= 0 && newY < M)
                    && arr[newX][newY]) {
                    q.push(p(newX, newY));
                    visited[newX][newY] = true;
                }
            }
        }
        level++;
    }
    cout << answer << '\n';
    return 0;
}