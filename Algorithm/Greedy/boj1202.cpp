#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
using p = pair<int, int>;
using ll = long long;
const int MAX = 3e5 + 5;

p jewelDetails[MAX];
multiset<int> bags;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N, K, M, V, C;
    ll answer = 0;

    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> M >> V;
        jewelDetails[i] = {M, V};
    }
    for (int i = 0; i < K; ++i) {
        cin >> C;
        bags.insert(C);
    }

    sort(jewelDetails, jewelDetails + N, [](p a, p b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second > b.second;
    });

    for (int i = 0; i < N; ++i) {
        if(bags.empty()) break;

        auto[jewelWeight, jewelValue] = jewelDetails[i];
        auto bag = bags.lower_bound(jewelWeight);
        if(bag == bags.end()) continue;
        bags.erase(bag);
        answer += jewelValue;
    }

    cout << answer << '\n';

    return 0;
}