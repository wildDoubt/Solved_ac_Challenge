// Brute force

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
const int MAX = 1e6 + 5;

inline void quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        vector<string> tempA;
        vector<string> tempB;
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 1; j < a.size()+1-i; ++j) {
                tempA.push_back(a.substr(i, j));
            }
        }
        for (int i = 0; i < b.size(); ++i) {
            for (int j = 1; j < b.size()+1-i; ++j) {
                tempB.push_back(b.substr(i, j));
            }
        }
        vector<int> answer;
        for (auto x:tempA) {
            for (auto y:tempB) {
                if(x==y){
                    answer.push_back(a.size()-x.size() + b.size()-y.size());
                }
            }
        }
        if(answer.empty()) cout<<a.size()+b.size()<<"\n";
        else cout<<*min_element(answer.begin(), answer.end())<<"\n";
    }
    return 0;
}