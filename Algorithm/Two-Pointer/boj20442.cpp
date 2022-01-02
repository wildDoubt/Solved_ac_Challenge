#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 3e6 + 1;

int rArr[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    string input;
    int answer = 0;
    cin >> input;

    int size = (int) input.length();
    for (int i = 1; i <= size; ++i) {
        rArr[i] = rArr[i - 1] + (input[i - 1] == 'R');
    }

    int s = -1, e = size;
    int k = 0;

    while (s < e && rArr[e] - rArr[s + 1] > 0) {
        answer = max(answer, rArr[e] - rArr[s + 1] + 2 * k);

        s++;
        e--;
        k++;

        while (s < size && input[s] != 'K') s++;
        while (e >= 0 && input[e] != 'K') e--;
    }
    cout << answer << '\n';
    return 0;
}