#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N, C, M;
    cin >> N >> C >> M;
    vector<tuple<int,int,int>> arr(M);
    int from, to, count;
    for (int i = 0; i < M; ++i) {
        cin >> from >> to >> count;
        arr[i] = make_tuple(from-1, to-1, count);
    }
    sort(arr.begin(), arr.end(), [](tuple<int, int, int> a, tuple<int, int, int> b) {
        return get<1>(a) < get<1>(b);
    });
    vector<int> canDeliver(N-1, C);
    int answer = 0, deliver;
    for (const auto &item : arr) {
        int currFrom = get<0>(item), currTo = get<1>(item), currCount = get<2>(item);
        deliver = min(*min_element(canDeliver.begin() + currFrom, canDeliver.begin() + currTo), currCount);
        if(deliver==0) continue;
        for (int i = currFrom; i < currTo; ++i) {
            canDeliver[i] -= deliver;
        }
        answer += deliver;
    }
    cout << answer << '\n';

    return 0;
}