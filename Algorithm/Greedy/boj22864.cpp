#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int A, B, C, M;
    cin >> A >> B >> C >> M;

    int work = 0, energy = 0;

    for (int i = 0; i < 24; ++i) {
        if (energy + A <= M) {
            work += B;
            energy += A;
        } else {
            energy = max(energy - C, 0);
        }
    }

    cout << work;

    return 0;
}