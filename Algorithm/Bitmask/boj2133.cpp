#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[32][1 << 3];
int N;

int calc(int pos, int status) {
    int &ret = dp[pos][status];
    if (ret != -1) return ret;
    if (pos > N + 1) return 0;
    if (pos == N + 1) {
        if (status == 0) return 1;
        return 0;
    }
    ret = 0;
    if (status == 0) {
        //000
        ret += calc(pos + 2, 0) + calc(pos + 1, 1) + calc(pos + 1, 4);
    } else if (status == 1) {
        //001
        ret += calc(pos + 1, 0) + calc(pos + 1, 6);
    } else if (status == 3) {
        //011
        ret += calc(pos + 1, 4);
    } else if (status == 4) {
        //100
        ret += calc(pos + 1, 0) + calc(pos + 1, 3);
    } else if (status == 6) {
        //110
        ret += calc(pos + 1, 1);
    } else if (status == 7) {
        //111
        ret += calc(pos + 1, 0);
    }
    return ret;
}

int main() {
    cin >> N;
    memset(dp, -1, sizeof(dp));
    cout << calc(1, 0) << '\n';
    return 0;
}