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

inline void quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool isPalindrome(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1]) return false;
    }
    return true;
}

int main() {
    quick_IO();
    int t;
    cin >> t;
    while (t--) {
        int n;
        int counts = 0;
        string endString;
        string s;
        cin >> n >> s;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') counts++;
        }
        if (isPalindrome(s)) {
            if (counts % 2 == 0 || counts == 1) {
                // 0의 개수가 1개고 palindrome이면 a는 무조건 1로 바꿔야 함.

                // 0의 개수가 짝수개면 모두 (0, 0)쌍으로만 존재한다.
                // A가 (0, 0) -> (0, 1)로 바꾸면 B도 따라서 (1, 1)로 바꾸는 걸 반복하는데
                // (0, 1)이 하나 남으면 b가 뒤집어 버리기 때문에 b가 이긴다.
                cout << "BOB\n";
            } else {
                // 0의 개수가 홀수고 palindrome이면 전체 길이가 홀수고 중간이 무조건 0이라는 뜻
                // a가 중간에 있는 0을 1로 바꿔주면 b는 (0, 0)인 쌍들만 받게 된다.
                // 위의 경우와 마찬가지로 b가 (0, 0)을 (0, 1)로 바꿔줄 때 a도 따라서 (0, 1)을 (1, 1)로
                // 바꿔주다가 (0, 1)이 하나 남았을 때 a가 뒤집으면 a가 반드시 승리한다.
                cout << "ALICE\n";
            }
        } else {
            if (n % 2 == 1 && s[n / 2] == '0' && counts == 2) {
                // 이 상황은 (0, 1)이 하나 있고 중간이 0인 상황
                // a가 (0, 1)인 쌍을 먼저 없애면 0이 하나 남기 때문에 비김
                // a가 뒤집어도 b가 (0, 1)인 쌍을 없애면 중앙에 0만 남아있는 상태가 되기 때문에 비김.
                cout << "DRAW\n";
            }else{
                // (0, 1)의 형태를 띠는 쌍을 찾아서 우선적으로 B가 0을 1로 바꿔줘야한다.
                // 그렇게 해야 b가 1로 바꿨을 때 palindrome이 되어서 A가 뒤집는 연산을 못하게 된다.
                // 이렇게 하지 않으면 A는 계속 뒤집음
                // => 근데 이러면 A가 (0, 1)인 쌍이 하나 남았을 때 뒤집지 않고 (0, 1)인 쌍을 없애주면 결국
                // b가 지게 된다.
                cout << "ALICE\n";
            }


        }
    }
    return 0;
}