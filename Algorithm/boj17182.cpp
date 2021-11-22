#include <iostream>
#include <cstdint>

using namespace std;

int adj[10][10];
int allVisited;
int N, K;
int answer = INT32_MAX;

void dfs(int prev, int curr, int total, int status) {
    if (prev == curr) return;
    if(status==allVisited){
        answer = min(total, answer);
        return;
    }else{
        for (int i = 0; i < N; ++i) {
            if (((status>>i)&1)==0) {
                status|=(1<<i);
                dfs(curr, i, total + adj[curr][i], status);
                status^=(1<<i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        allVisited|=(1<<i);
        for (int j = 0; j < N; ++j) {
            cin >> adj[i][j];
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (adj[i][j] > adj[i][k] + adj[k][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    dfs(-1, K, 0, (1<<(K)));
    cout << answer << '\n';
    return 0;
}