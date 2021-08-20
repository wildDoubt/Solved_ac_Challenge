#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
const int MAX = 1e6 + 2;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll pArr[MAX];
ll answer = 0;
int counter[MAX/2];

int main() {
    Quick_IO();
    int N, M;
    cin >> N >> M;
    counter[0]++;
    for (int i = 1, input; i <= N; ++i) {
        cin >> input;
        pArr[i] += pArr[i - 1] + input;
        counter[pArr[i] % M]++;
    }

    for (auto x:counter) {
        answer += (x * (x - 1ll)) / 2ll;
    }
    cout << answer << '\n';
    return 0;
}