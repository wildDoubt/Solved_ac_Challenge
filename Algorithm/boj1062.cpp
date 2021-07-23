#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool visited[26];
string arr[51];
int N, K;
int answer;

int check() {
    int counts = 0;
    for (int i = 0; i < N; ++i) {
        bool flag = true;
        for (char j : arr[i]) {
            if (!visited[j - 'a']) {
                flag = false;
                break;
            }
        }
        if (flag) {
            counts++;
        }
    }
    return counts;
}

void dfs(int curr, int depth) {
    if (depth == K - 5) {
        answer = max(answer, check());
    } else {
        for (int i = curr; i < 26; ++i) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(i, depth + 1);
                visited[i] = false;
            }
        }
    }
}

int main() {
    Quick_IO();

    cin >> N >> K;
    visited['a' - 'a'] = true;
    visited['n' - 'a'] = true;
    visited['t' - 'a'] = true;
    visited['i' - 'a'] = true;
    visited['c' - 'a'] = true;
    set<int> S;
    for (int i = 0; i < N; ++i) {
        string a;
        cin >> a;
        string temp = a.substr(4, a.length() - 8);
        arr[i] = temp;
        for (char ch : temp) {
            S.insert(ch - 'a');
        }
    }

    if (K < 5) {
        cout << 0 << '\n';
    } else {
        dfs(1, 0);
        cout << answer << '\n';
    }
    return 0;
}