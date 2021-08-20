#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int K;

unordered_set<int> possible[9];

void calc(int sum, int a, int b) {
    possible[sum].insert(a + b);
    if (a != b) possible[sum].insert(abs(a - b));
    if (b > a) swap(a, b);
    possible[sum].insert(a / b);
    possible[sum].insert(a * b);
}

int main() {
    Quick_IO();
    int n;
    cin >> K >> n;
    int temp = K;
    for (int i = 1; i <= 8; ++i) {
        possible[i].insert(temp);
        temp = 10 * temp + K;
    }

    for (int i = 1; i < 8; ++i) {
        for (int j = 1; i + j <= 8; ++j) {
            for (auto x: possible[i]) {
                for (auto y:possible[j]) {
                    calc(i + j, x, y);
                }
            }
        }
    }

    for (int i = 0, input; i < n; ++i) {
        cin >> input;
        int answer = -1;
        for (int j = 1; j <= 8; ++j) {
            if (possible[j].count(input)) {
                answer = j;
                break;
            }
        }
        answer != -1 ? cout << answer : cout << "NO";
        cout << '\n';
    }

    return 0;
}