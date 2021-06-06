#include <iostream>
#include <algorithm>
#include <functional>
#include <set>
#include <queue>
#include <sstream>

using namespace std;

typedef struct coord {
    int m;
    int n;
    int h;

    coord(int a, int b, int c) {
        m = a;
        n = b;
        h = c;
    }
} coord;


bool visited[100][100][100];


int main() {
    int M, N, H;
    cin >> M >> N >> H;
    int arr[H][N][M];
    int dx[6] = {-1, 1, 0, 0, 0, 0};
    int dy[6] = {0, 0, -1, 1, 0, 0};
    int dz[6] = {0, 0, 0, 0, -1, 1};
    queue<coord> q;
    int total = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                int a;
                cin >> a;
                if (a == 1) q.push(coord(k, j, i));
                else if (a == 0) total++;
                arr[i][j][k] = a;
            }
        }
    }
    function<bool(int, int, int)> checkRange = [M, N, H](int m, int n, int h) {
        if (0 <= m && m < M && 0 <= n && n < N && 0 <= h && h < H) return true;
        return false;
    };
    int level = -1;
    while (!q.empty()) {
        int size = (int) q.size();
        for (int i = 0; i < size; ++i) {
            coord curr = q.front();
            auto[currM, currN, currH] = curr;
            q.pop();
            for (int j = 0; j < 6; ++j) {
                if (checkRange(currM + dx[j], currN + dy[j], currH + dz[j]) &&
                    !visited[currH + dz[j]][currN + dy[j]][currM + dx[j]] &&
                    arr[currH + dz[j]][currN + dy[j]][currM + dx[j]] == 0) {
                    q.push(coord(currM + dx[j], currN + dy[j], currH + dz[j]));
                    arr[currH + dz[j]][currN + dy[j]][currM + dx[j]] = 1;
                    visited[currH + dz[j]][currN + dy[j]][currM + dx[j]] = true;
                    total--;
                }
            }
        }
        level++;
    }
    if (total == 0) {
        cout << level << "\n";
    } else {
        cout << -1 << "\n";
    }
    return 0;
}