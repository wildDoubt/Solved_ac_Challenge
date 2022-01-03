#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

vector<ll> arr[4];
vector<ll> merged[2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    ll answer = 0ll;
    cin >> n;
    int merged_size = n * n;
    for (int i = 0; i < 4; ++i) arr[i].resize(n);
    for (int i = 0; i < 2; ++i) merged[i].resize(merged_size);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> arr[j][i];
        }
    }
    /*
     * merged[0] = arr[0] + arr[1]의 모든 결과
     * merged[1] = arr[2] + arr[3]의 모든 결과
     */
    for (int k = 0; k < 2; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                merged[k][i*n + j] = arr[k*2][i] + arr[k*2+1][j];
            }
        }
    }

    for (int i = 0; i < 2; ++i) sort(merged[i].begin(), merged[i].end());

    for (int i = 0; i < merged_size; ++i) {
        ll find = -merged[0][i];
        auto e = upper_bound(merged[1].begin(), merged[1].end(), find);
        auto s = lower_bound(merged[1].begin(), merged[1].end(), find);

        if(find == *s){
            answer += (e - s);
        }
    }

    cout<<answer<<'\n';

    return 0;
}