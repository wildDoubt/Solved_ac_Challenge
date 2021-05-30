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
const int MAX = 1e6+5;

inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll arr[51];

int main(){
    quick_IO();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for (int i = 0; i < 2 * n; ++i) {
            cin>>arr[i];
        }
        sort(arr, arr+2*n);
        vector<ll> answer;
        for (int i = 0; i < n; ++i) {
            answer.push_back(arr[i]);
            answer.push_back(arr[n+i]);
        }
        for (auto x:answer) {
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    return 0;
}