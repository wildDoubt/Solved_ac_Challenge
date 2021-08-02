#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

char arr[15];
bool visited[20];

int C, L;

bool isVowel(char a) {
    return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
}

void dfs(int curr, const string &s) {
    if ((int) s.size() == L) {
        int vowel = 0;
        int consonant = 0;
        for (auto c:s) isVowel(c) ? vowel++ : consonant++;
        if (vowel > 0 && consonant > 1) cout << s << '\n';
    }
    for (int i = curr + 1; i < C; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i, s + arr[i]);
            visited[i] = false;
        }

    }
}

int main() {
    Quick_IO();
    cin >> L >> C;

    for (int i = 0; i < C; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + C);
    dfs(-1, "");
    return 0;
}