#include <iostream>
#include <algorithm>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool visited[30][30];
int N;
double P[4];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

double dfs(int x, int y, int n) {
    if (n == 0) return 1.0;

    visited[x][y] = true;
    double p = 0.0;
    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if(visited[newX][newY]) continue;
        p += (dfs(newX, newY, n - 1) * P[i]);
    }
    visited[x][y] = false;
    return p;
}

int main() {
    Quick_IO();
    cout.precision(15);

    cin >> N;

    for (double & i : P) {
        int a;
        cin >> a;
        i = a / 100.0;
    }

    cout << dfs(14, 14, N) << '\n';
    return 0;
}