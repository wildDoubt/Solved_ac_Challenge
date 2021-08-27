#include <iostream>
#include <algorithm>

using namespace std;
using p = pair<int, int>;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int N, M, answer;

int board[500][500];

p tet[5][3] = {
        {p(0, 1), p(0, 2), p(0, 3)},
        {p(0, 1), p(1, 0), p(1, 1)},
        {p(1, 0), p(2, 0), p(2, 1)},
        {p(1, 0), p(1, 1), p(2, 1)},
        {p(0, 1), p(0, 2), p(1, 1)},
};

bool checkRange(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < M;
}

p rotate(p coord, int option) {
    int x = coord.first, y = coord.second;
    if (option == 0) return {x, y};
    else if (option == 1) return {-x, y};
    else if (option == 2) return {x, -y};
    else if (option == 3) return {-x, -y};
    else if (option == 4) return {y, x};
    else if (option == 5) return {-y, x};
    else if (option == 6) return {-y, -x};
    else return {y, -x};
}

void calc(int x, int y, int option) {
    vector<int> result(8, board[x][y]);
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 3; ++j) {
            auto[newX, newY] = rotate(tet[option][j], i);
            newX += x;
            newY += y;
            if (checkRange(newX, newY)) {
                result[i] += board[newX][newY];
            }
        }
    }
    answer = max(answer, *max_element(result.begin(), result.end()));
}

int main() {
    Quick_IO();

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }


    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < 5; ++k) {
                calc(i, j, k);
            }
        }
    }
    cout << answer << '\n';

    return 0;
}