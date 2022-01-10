#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        int arr[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        vector<bool> comb(n, false);
        for (int j = 0; j < 6; j++) comb[j] = true;
        do {
//            for (int i = 0; i < n; ++i) {
//                if(comb[i]) cout << arr[i] << ' ';
//            }
            for (int i = 0; i < n; ++i) {
                cout << comb[i] << ' ';
            }
            cout << '\n';
        } while (prev_permutation(comb.begin(), comb.end()));
        cout << '\n';
    }

    return 0;
}