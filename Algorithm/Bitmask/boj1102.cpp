#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 0x66554433;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int N, P;
int adj[16][16];
int answer = INF;
int dp[1 << 16];

bool check(int status) {
    // P개 이상 1인지 확인
    int total = 0;
    for (int i = 0; i < N; ++i) {
        if ((status >> i) & 1) total++;
    }
    if (total >= P) return true;
    return false;
}

int calc(int status) {
    int &ret = dp[status];
    if (ret != -1) return ret;
    if (check(status)) return ret = 0;
    ret = INF;
    for (int i = 0; i < N; ++i) {
        if ((status >> i) & 1) {
            for (int j = 0; j < N; ++j) {
                if (((status >> j) & 1) == 0) {
                    ret = min(ret, calc(status | (1 << j)) + adj[i][j]);
                }
            }
        }
    }
    return ret;
}

int main() {
    Quick_IO();
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> adj[i][j];
        }
    }

    string temp;
    int value = 0;
    cin >> temp;
    cin >> P;
    int size = (int) temp.size();
    for (int i = 0; i < size; ++i) {
        if (temp[i] == 'Y') value |= (1 << i);
    }
    fill(dp, dp + (1 << N), -1);
    answer = calc(value);
    if(answer==INF) cout<<"-1\n";
    else cout<<answer<<'\n';

    return 0;
}