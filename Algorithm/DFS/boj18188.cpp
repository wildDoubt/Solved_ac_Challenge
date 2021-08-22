#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
using p = pair<int, int>;
using node = pair<p, string>;

string board[25];

bool moves[25][4];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int dao_x, dao_y;
int dizini_x, dizini_y;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    const string temp = "WASD";

    int H, W, N;
    char first, second;
    cin >> H >> W;
    for (int i = 0; i < H; ++i) {
        cin >> board[i];
    }
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> first >> second;
        for (int j = 0; j < 4; ++j) {
            if (first == temp[j] || second == temp[j]) moves[i][j] = true;
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (board[i][j] == 'D') dao_x = i, dao_y = j;
            if (board[i][j] == 'Z') dizini_x = i, dizini_y = j;
        }
    }

    queue<node> q;
    q.push(node(p(dao_x, dao_y), ""));

    int level = 0;
    while (!q.empty()) {
        int size = (int) q.size();

        if (level > N) break;

        for (int i = 0; i < size; ++i) {
            int currX = q.front().first.first;
            int currY = q.front().first.second;
            string currPath = q.front().second;
            if (currX == dizini_x && currY == dizini_y) {
                cout<<"YES\n";
                cout<<currPath<<'\n';
                return 0;
            }
            q.pop();
            for (int j = 0; j < 4; ++j) {
                int newX = currX + dx[j];
                int newY = currY + dy[j];
                if (newX >= 0 && newX < H &&
                    newY >= 0 && newY < W &&
                    board[newX][newY] != '@' &&
                    moves[level][j]) {
                    q.push(node(p(newX, newY), currPath + temp[j]));
                }
            }
        }
        level++;
    }
    cout<<"NO\n";
    return 0;
}