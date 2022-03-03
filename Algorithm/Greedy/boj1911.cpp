#include <iostream>
#include <algorithm>

using namespace std;
using p = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N, L, start, end;
    cin >> N >> L;
    p arr[N];
    for (int i = 0; i < N; ++i) {
        cin >> start >> end;
        arr[i] = {start, end};
    }

    sort(arr, arr + N, [](p a, p b) {
        return a.first < b.first;
    });

    int currIndex = 0, answer = 0;
    for (int i = 0; i < N; ++i) {
        auto[s, e] = arr[i];

        int startIndex = max(currIndex, s);
        int holeLength = e - startIndex;
        if(holeLength <= 0) continue;

        int woodCount = holeLength / L;
        if (holeLength % L != 0) {
            ++woodCount;
        }
        answer += woodCount;
        currIndex = startIndex + woodCount * L;
    }
    cout << answer << '\n';

    return 0;
}