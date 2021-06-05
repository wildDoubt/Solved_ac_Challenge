#define LOCAL

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;
using p = pair<int, int>;
using ll = long long;
const int MAX = 10e+6;
const int INF = 0x66554433;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    int N, M;
    string S;
    cin >> N >> M >> S;
    int index = 0;
    int answer = 0;
    while (S[index] != 'I') index++;
    index++;
    while (index <= (int) S.size() - 2 * N - 1) {
        int counts = 0;
        while (true) {
            if (S[index] == 'O' && S[index + 1] == 'I') {
                if (counts >= N - 1)
                    answer++;
                counts++;
                index += 2;
            } else {
                break;
            }
        }
        while (index <= (int) S.size() - 2 * N - 1 && S[index] != 'I') index++;

        index++;
    }
    cout << answer << "\n";
    return 0;
}