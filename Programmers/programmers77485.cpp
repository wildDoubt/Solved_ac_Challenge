#include <iostream>
#include <vector>

using namespace std;
using p = pair<int, int>;

int rotateBoard(vector<vector<int>> &board, const vector<int> &query) {
    int x1 = query[0] - 1, y1 = query[1] - 1;
    int x2 = query[2] - 1, y2 = query[3] - 1;
    vector<p> original;
    int temp = board[x1][y1];
    int minValue = temp;
    for (int i = x1 + 1; i <= x2; ++i) {
        board[i - 1][y1] = board[i][y1];
        minValue = min(board[i][y1], minValue);
    }

    for (int i = y1 + 1; i <= y2; ++i) {
        board[x2][i - 1] = board[x2][i];
        minValue = min(board[x2][i], minValue);
    }

    for (int i = x2 - 1; i >= x1; --i) {
        board[i + 1][y2] = board[i][y2];
        minValue = min(board[i][y2], minValue);
    }

    for (int i = y2 - 1; i >= y1; --i) {
        board[x1][i + 1] = board[x1][i];
        minValue = min(board[x1][i], minValue);
    }
    board[x1][y1+1] = temp;
    return minValue;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> boards(rows, vector<int>(columns));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            boards[i][j] = i * columns + j + 1;
        }
    }

    answer.reserve(queries.size());
    for (const auto &query : queries) {
        answer.push_back(rotateBoard(boards, query));
    }
    return answer;
}

int main() {
    vector<int> answer;
    vector<vector<int>> queries = vector<vector<int>>{
            vector<int>{2, 2, 5, 4},
            vector<int>{3, 3, 6, 6},
            vector<int>{5, 1, 6, 3}
    };
    answer = solution(6, 6, queries);
    for (auto x:answer) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}