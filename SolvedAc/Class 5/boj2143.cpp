#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
const int MAX = 1e3 + 2;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int A[MAX], B[MAX], pA[MAX], pB[MAX];
vector<int> sA, sB;

int main() {
    Quick_IO();

    int T, N, M;
    cin >> T;

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        pA[i] += pA[i - 1] + A[i];
    }

    cin >> M;
    for (int i = 1; i <= M; ++i) {
        cin >> B[i];
        pB[i] += pB[i - 1] + B[i];
    }

    int newSizeA =(N*(N+1))/2, indexA=0;
    sA.resize(newSizeA);
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            sA[indexA++] = pA[j] - pA[i];
        }
    }

    int newSizeB =(M*(M+1))/2, indexB = 0;
    sB.resize(newSizeB);
    for (int i = 0; i < M; ++i) {
        for (int j = i + 1; j <= M; ++j) {
            sB[indexB++] = pB[j] - pB[i];
        }
    }

    sort(sA.begin(), sA.end()), sort(sB.begin(), sB.end());
    ll answer = 0;
    for (auto x:sA) {
        int find = T - x;
        if (find == *lower_bound(sB.begin(), sB.end(), find)) {
            answer += (upper_bound(sB.begin(), sB.end(), find)-lower_bound(sB.begin(), sB.end(), find));
        }
    }
    cout<<answer<<'\n';
    return 0;
}