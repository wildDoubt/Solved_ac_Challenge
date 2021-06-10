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

int calc(int left, int right, int index){
    return min(index - left, abs(right-index-1));
}

int main() {
    Quick_IO();
    int t;
    cin >> t;
    while (t--) {
        int n;
        int answer = 0;
        cin >> n;
        deque<int> arr;
        int x1, x2;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            arr.push_back(a);
            if (a == 1) x1 = i;
            if (a == n) x2 = i;
        }

        vector<int> temp;

        temp.push_back(max(x1, x2)+1);
        temp.push_back(n-min(x1, x2));
        temp.push_back(calc(0, n, x1)+calc(0, n, x2)+2);
        // cout<<calc(0, n, x1)<<" "<<calc(0, n, x2)<<" "<<d<<endl;
        cout<<*min_element(temp.begin(), temp.end())<<"\n";
    }

    return 0;
}