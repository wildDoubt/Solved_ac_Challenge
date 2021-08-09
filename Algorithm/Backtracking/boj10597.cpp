#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool visited[51];
vector<int> answer;
string input;

void dfs(int curr) {
    int size = (int) input.size();
    if (curr == size) {
        if (*max_element(answer.begin(), answer.end()) <= size) {
            for (auto v:answer) {
                cout << v << ' ';
            }
            cout << '\n';
            exit(0);
        }
        return;
    }
    for (int i = 1; i <= 2; ++i) {
        int x = input.substr(curr, i)[0]!='0'?stoi(input.substr(curr, i)):-1;
        if (curr < size + 1 - i && !visited[x] && x <= 50 && x >= 1) {
            answer.push_back(x);
            visited[x] = true;
            dfs(curr + i);
            visited[x] = false;
            answer.pop_back();
        }

    }
}

int main() {
    Quick_IO();
    cin >> input;
    dfs(0);
    return 0;
}