#include <iostream>
#include <algorithm>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    Quick_IO();
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int d = C * D - B;

    if (d <= 0) {
        cout << "-1\n";
    } else {
        if (A % d==0) cout << A / d << '\n';
        else cout << A / d + 1 << '\n';
    }

    return 0;
}