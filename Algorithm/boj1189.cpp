#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
using p = pair<int, int>;

struct node {
    p coord;
    int distance;
    int status;

    node(p a, int b, int c) {
        coord = a;
        distance = b;
        status = c;
    }
};

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int R, C, K;
    int initialStatus = 0;
    int answer = 0;
    string input;
    cin >> R >> C >> K;

    for (int i = 0; i < R; ++i) {
        cin >> input;
        for (int j = 0; j < C; ++j) {
            if (input[j] != '.') {
                initialStatus |= (1 << (i * C + j));
            }
        }
    }

    queue<node> q;
    q.push(node(p(R - 1, 0), 1, initialStatus | (1 << ((R - 1) * C))));

    while (!q.empty()) {
        int size = (int) q.size();
        for (int i = 0; i < size; ++i) {
            node curr = q.front();
            q.pop();
            auto[currX, currY] = curr.coord;
            int currStatus = curr.status;
            int currDistance = curr.distance;

            if (currX == 0 && currY == C - 1) {
                if (currDistance == K) answer++;
                break;
            }

            for (int j = 0; j < 4; ++j) {
                int nextX = currX + dx[j], nextY = currY + dy[j];
                if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C
                    && !(currStatus & (1 << (nextX * C + nextY)))) {
                    q.push(node(p(nextX, nextY), currDistance + 1, currStatus | (1 << (nextX * C + nextY))));
                }
            }
        }
    }
    cout << answer << '\n';
    return 0;
}