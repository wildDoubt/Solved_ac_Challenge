#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using p = pair<int, int>;

const int INF = 0x66554433;
const int MAX = 1e6 + 5;

inline void quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int arr[51];
int n;

bool check(int start, int end) {
    for (int i = start; i < end - 1; ++i) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}

bool check1(int start, int end) {
    for (int i = start; i < end - 1; ++i) {
        if (arr[i] < arr[i + 1]) return false;
    }
    return true;
}

int main() {
    quick_IO();
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        if (arr[0] == *max_element(arr, arr + n) &&
            arr[n - 1] == *min_element(arr, arr + n)) {
            cout << "3\n";
            continue;
        }
        if (check(0, n)) {
            cout << "0\n";
        } else {
            if (arr[0] == *min_element(arr, arr + n) ||
                arr[n - 1] == *max_element(arr, arr + n)) {
                cout << "1\n";
            } else {
                int index;
                for (index = 1; index < n; ++index) {
                    if (arr[index] > arr[0]) {
                        break;
                    }
                }
                if (index == n) {
                    cout << "2\n";
                } else {
                    if (check(index, n)) {
                        cout << "1\n";
                    } else {
                        cout << "2\n";
                    }
                }

            }
        }

    }
    return 0;
}