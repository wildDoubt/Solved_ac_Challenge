#include <iostream>

using namespace std;

int other[3] = {3, 2, 1};

void solve(int from, int to, int n) {
    if (n == 1) {
        cout << from << ' ' << to << '\n';
        return;
    }
    // 1+2=3 0=> 3
    // 2+3=5 2=> 1
    // 1+3=4 1=> 2
    int otherNumber = other[(from + to) % 3];
    solve(from, otherNumber, n - 1);
    solve(from, to, 1);
    solve(otherNumber, to, n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N;
    cin >> N;

    cout << ((1<<N) - 1) << '\n';
    solve(1, 3, N);

    return 0;
}