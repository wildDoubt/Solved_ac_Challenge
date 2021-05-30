#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using p = pair<int, int>;

const int INF = 0x66554433;
const int MAX = 2e5+5;

inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}



int main(){
    quick_IO();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            int a;
            cin>>a;
            m[a]++;
        }
        int maxValue = -INF;
        for (auto x:m) {
            maxValue = max(x.second, maxValue);
        }
        if(maxValue>n/2) cout<<n - (n-maxValue)*2<<"\n";
        else cout<<n%2<<"\n";
    }
    return 0;
}