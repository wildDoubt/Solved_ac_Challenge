#define LOCAL

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
using ll = long long;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int board[101][101];
ll dp[101][101];
int N;

ll calc(int x, int y){
    if(x==N-1&&y==N-1) {
        return dp[x][y]=1;
    }
    if(y>=N||x>=N||board[x][y]==0) return 0;

    if(dp[x][y]!=-1){
        return dp[x][y];
    }
    int new_x = x+board[x][y];
    int new_y = y+board[x][y];
    return dp[x][y] = calc(new_x, y) + calc(x, new_y);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Quick_IO();
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>board[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout<<calc(0, 0)<<'\n';
    return 0;
}