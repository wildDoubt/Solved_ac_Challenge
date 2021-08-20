#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
const int MAX = 2e5 + 5;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int pArr[MAX][27];

int main() {
    Quick_IO();

    string inputString;
    int q;
    cin >> inputString >> q;
    inputString = " " + inputString;
    for (int i = 1; i <= (int) inputString.length(); ++i) {
        for (int j = 0; j < 26; ++j) {
            pArr[i][j] += pArr[i - 1][j];
            if (j == inputString[i] - 'a') pArr[i][j]++;
        }
    }

    char ch;
    int l, r;
    for (int i = 0; i < q; ++i) {
        cin >> ch >> l >> r;
        cout << pArr[r + 1][ch - 'a'] - pArr[l][ch - 'a'] << '\n';
    }

    return 0;
}