//#define LOCAL

#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
//#include <ctime>

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
p arr[MAX]; // <b, number>

int main() {
//#ifdef LOCAL
//    freopen("boj22899_input.txt", "r", stdin);
//    freopen("boj22899_output.txt", "w", stdout);
//#endif
    Quick_IO();
//    auto start = clock();
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        arr[i] = p(a, A[i]);
    }

    sort(arr, arr + N, [](p a, p b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    unordered_map<int, int> M1;
    unordered_map<int, int> M2;
    for (int i = 0; i < N; ++i) M1[arr[i].second]++;
    for (int i = 0; i < K; ++i) M2[arr[i].second]++;
    int limit = (*max_element(M2.begin(), M2.end(), [](p a, p b) {
        return a.second < b.second;
    })).second;
    ll limitAnswer = 0;
    for (int i = 0; i < K; ++i) {
        limitAnswer += arr[i].first;
    }
    for (int i = 1; i <= N; ++i) {
        if (i >= limit) {
            cout << limitAnswer;
        } else {
            int temp1 = 0;
            for (auto x:M1) {
                temp1 += min(i, x.second);
            }
            if (temp1 < K) {
                cout << -1 << " ";
                continue;
            }
            unordered_map<int, int> temp;
            int counts = 0;
            ll answer = 0;
            int index = 0;
            while (counts < K) {
                if (temp[arr[index].second] < i) {
                    answer += arr[index].first;
                    temp[arr[index].second]++;
                    counts++;
                }
                index++;
            }
            cout << answer;
        }
        cout << " ";
    }
//    auto end = clock();
//    cout<<'\n'<<(double)(end-start)/CLOCKS_PER_SEC<<"s\n";
    return 0;
}