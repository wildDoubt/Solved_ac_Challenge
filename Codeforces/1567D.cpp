#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t, n, s;
    cin >> t;
    while (t--) {
        cin >> s >> n;
        if (n == 1) {
            cout << s << '\n';
            continue;
        }
        int answer[n];
        fill(answer, answer + n, 0);
        int index = 0;
        for (int i = 1e8; i >= 1; i /= 10) {
//             cout<<"index: "<<s-i<<" "<<n-index-1<<"\n";
//             s-i >= n-index-1
//             단순히 n - index - 1 > 0 이면 나눌 수 있지 않을까??
//             => 그러면 나누어줘야 하는 수가 더 작은 경우가 발생할 수 있다.
//             결론: 남은 s를 나누어줘야 하는데 이 조건을 만족해야 올바르게 나누어 줄 수 있다.
            while (s >= i && s - i >= n - index - 1) {
                answer[index] += i;
                s -= i;
                index = min(index + 1, n - 1);
            }
        }

        for (auto x:answer)cout << x << ' ';
        cout << '\n';
    }

    return 0;
}