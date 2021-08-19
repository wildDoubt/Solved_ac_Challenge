#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
using p = pair<int, int>;
using ll = long long;
const int MAX = 1e5 + 5;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int A[MAX];
p arr[MAX];

int main() {
    Quick_IO();
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; ++i) cin >> A[i];

    for (int i = 0, a; i < N; ++i) {
        cin >> a;
        arr[i] = p(a, A[i]);
    }

    sort(arr, arr + N, [](p a, p b) { return a.first < b.first; });

    unordered_map<int, int> M;
    int limit;
    ll answer;
    ll limitAnswer = 0;

    for (int i = 0; i < N; ++i) {
        M[arr[i].second]++;
        if (i == K-1) {
            limit = (*max_element(M.begin(), M.end(), [](p a, p b) {
                return a.second < b.second;
            })).second;
        }
        if (i < K) {
            limitAnswer += arr[i].first;
        }
    }

    for (int i = 1; i <= N; ++i, answer = 0) {
        if (i >= limit) {
            answer = limitAnswer;
        } else {
            int temp1 = 0;
            for (auto x:M) {
                temp1 += min(i, x.second);
            }
            if (temp1 < K) {
                answer = -1;
            } else {
                unordered_map<int, int> temp;
                int counts = 0;
                for (int index = 0; counts < K; ++index) {
                    if (temp[arr[index].second] < i) {
                        answer += arr[index].first;
                        temp[arr[index].second]++;
                        counts++;
                    }
                }
            }
        }
        cout << answer << ' ';
    }
    return 0;
}