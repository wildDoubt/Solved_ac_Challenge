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
        ll answer = 0l;
        int n;
        int temp;
        cin>>n;
        map<ll, ll> arr;
        for (int i = 0; i < n; ++i) {
            cin>>temp;
            answer += arr[temp-i];
            arr[temp-i]++;
        }

        cout<<answer<<"\n";
    }
    return 0;
}