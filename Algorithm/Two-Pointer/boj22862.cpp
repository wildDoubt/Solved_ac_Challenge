#include <iostream>

using namespace std;
const int MAX = 1e6 + 1;

int pArr[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N, K, answer = 0;
    cin >> N >> K;

    for (int i = 0, input; i < N; ++i) {
        cin >> input;
        pArr[i + 1] = pArr[i] + input % 2;
    }

    int s = 0, e = 1;

    while (e <= N) {
        int odd_number = pArr[e] - pArr[s];

        if (K < odd_number) {
            s++;
        } else if (K >= odd_number) {
            answer = max(answer, e - s - odd_number);
            e++;
        }
    }

    cout << answer << '\n';

    return 0;
}