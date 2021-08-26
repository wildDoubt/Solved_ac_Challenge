#include <iostream>
#include <algorithm>

using namespace std;
using p = pair<int, int>;
using ll = long long;
const int MAX = 1e6;
const int INF = 0x66554433;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<string> map;
bool visited1[100][100];
bool visited2[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int N, answer1, answer2;

void dfs1(int x, int y) {
    visited1[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int newX = dx[i] + x, newY = dy[i] + y;
        if (newX >= 0 && newX < N &&
            newY >= 0 && newY < N &&
            !visited1[newX][newY] && map[newX][newY] == map[x][y]) {
            dfs1(newX, newY);
        }
    }
}

void dfs2(int x, int y) {
    visited2[x][y] = true;
    if (map[x][y] == 'B') {
        for (int i = 0; i < 4; ++i) {
            int newX = dx[i] + x, newY = dy[i] + y;
            if (newX >= 0 && newX < N &&
                newY >= 0 && newY < N &&
                !visited2[newX][newY] && map[newX][newY] == 'B') {
                dfs2(newX, newY);
            }
        }
    } else {
        for (int i = 0; i < 4; ++i) {
            int newX = dx[i] + x, newY = dy[i] + y;
            if (newX >= 0 && newX < N &&
                newY >= 0 && newY < N &&
                !visited2[newX][newY] && map[newX][newY] != 'B') {
                dfs2(newX, newY);
            }
        }
    }
}

int main() {
    Quick_IO();

    cin >> N;
    for (int i = 0; i < N; ++i) {
        string a;
        cin >> a;
        map.push_back(a);
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited2[i][j]) {
                dfs2(i, j);
                answer2++;
            }
            if (!visited1[i][j]) {
                dfs1(i, j);
                answer1++;
            }
        }
    }
    cout << answer1 << " " << answer2 << '\n';
    return 0;
}