#include <iostream>
#include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int minDP[2][3];
    int maxDP[2][3];

    int N, input[3];
    cin>>N;

    memset(minDP, 0, sizeof(minDP));
    memset(maxDP, 0, sizeof(maxDP));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin>>input[j];
            minDP[1][j] = input[j];
            maxDP[1][j] = input[j];
            minDP[1][j] += min(minDP[0][1], j==1?min(minDP[0][0], minDP[0][2]):minDP[0][j]);
            maxDP[1][j] += max(maxDP[0][1], j==1?max(maxDP[0][0], maxDP[0][2]):maxDP[0][j]);
        }
//        for (int j = 0; j < 3; ++j) {
//            minDP[0][j] = minDP[1][j];
//            maxDP[0][j] = maxDP[1][j];
//        }
        memcpy(minDP[0], minDP[1], sizeof(int)*3);
        memcpy(maxDP[0], maxDP[1], sizeof(int)*3);
    }

    cout<<*max_element(maxDP[0], maxDP[1])<<' ';
    cout<<*min_element(minDP[0], minDP[1])<<'\n';

    return 0;
}