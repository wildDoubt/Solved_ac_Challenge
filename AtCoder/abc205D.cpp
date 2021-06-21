#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>
#include <sstream>
#include <map>
#include <climits>
using namespace std;
using p = pair<int, int>;
using ll = long long;
using pll = pair<ll, int>;
const int MAX = 10e+6;
const int INF = 0x66554433;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    Quick_IO();
    int N, Q;
    cin >> N >> Q;
    vector<ll> s(N);
    vector<pll> T;
    cin >> s[0];
    int a = 1;
    int startIndex = 0;
    ll maxValue = s[0];
    ll minValue = s[0];
    for (int i = 1; i < N; ++i) {
        cin >> s[i];
        maxValue = max(maxValue, s[i]);
        minValue = min(minValue, s[i]);
        if (s[i - 1] + 1 == s[i]) {
            a++;
        } else {
            T.emplace_back(s[startIndex], a);
            startIndex = i;
            a++;
        }
    }
    T.emplace_back(s[startIndex], a);
    for (auto x:T) {
        cout << x.first << " " << x.second << endl;
    }
    for (int i = 0; i < Q; ++i) {
        ll b;
        cin>>b;
        if(maxValue<b){
            cout<<b+N<<"\n";
            continue;
        }
        auto c = *(upper_bound(T.begin(), T.end(), pll(b, 0), [](pll c, pll d){
            return c.first<d.first;
        })-1);
        cout<<c.second<<"+"<<b<<"="<<c.second+b<<endl;
    }

    return 0;
}