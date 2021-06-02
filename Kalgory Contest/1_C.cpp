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

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

struct compare {
    bool operator()(p a, p b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

int main() {
    Quick_IO();
    int N, L;
    cin >> N >> L;
    priority_queue<p, vector<p>, compare> v;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        v.push(p(a, b));
    }
    int answer = 0;
    int idx = 0;
    while (!v.empty()) {
        if(idx>=v.top().second){
            break;
        }
        idx = max(idx, v.top().first);

        answer += (v.top().second - idx - 1) / L + 1;
        idx += (((v.top().second - idx - 1) / L + 1) * L);

        v.pop();
    }
    cout << answer << "\n";
    return 0;
}