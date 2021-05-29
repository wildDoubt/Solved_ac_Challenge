// 35분
// container의 size()를 int로 꼭 바꿔주자...

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>
#include <sstream>

using namespace std;
using p = pair<int, int>;
using ll = long long;
const int MAX = 10e+6;
const int INF = 0x66554433;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

deque<string> split(string input, char delimiter) {
    deque<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

int main() {
    Quick_IO();
    int t;
    cin >> t;
    while (t--) {
        string p, temp;
        int n;
        cin >> p >> n >> temp;
        temp = temp.substr(1, (temp.size() - 2) < 0 ? 0 : (temp.size() - 2));
        auto arr = split(temp, ',');
        bool reverse = false;
        bool error = false;
        for (auto ch:p) {
            if (ch == 'R') {
                reverse = !reverse;
            } else if (ch == 'D') {
                if (arr.empty()) {
                    error = true;
                    cout << "error\n";
                    break;
                }
                if (!reverse) {
                    arr.pop_front();
                } else {
                    arr.pop_back();
                }
            }
        }

        if (!error) {
            cout << "[";
            if (!reverse) {
                for (int i = 0; i < (int)arr.size() - 1; i++) {
                    cout << arr[i] << ",";
                }
                if (!arr.empty())
                    cout << arr[arr.size() - 1];
            } else {
                for (int i = (int) arr.size() - 1; i > 0; i--) {
                    cout << arr[i] << ",";
                }
                if (!arr.empty())
                    cout << arr[0];
            }
            cout << "]\n";
        }
    }

    return 0;
}