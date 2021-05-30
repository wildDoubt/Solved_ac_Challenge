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
    quick_IO();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<int> minS;
        set<int> maxS;
        vector<int> minimal(n, 0);
        vector<int> maximum(n, 0);
        for (int i = 1; i <= n; ++i) {
            minS.insert(i);
            maxS.insert(i);
        }
        int prev;
        cin>>prev;
        minS.erase(prev);
        maxS.erase(prev);
        minimal[0] = prev;
        maximum[0] = prev;
        for (int i = 1; i < n; ++i) {
            int a;
            cin>>a;
            if(prev!=a){
                minimal[i] = a;
                minS.erase(a);
                prev = a;

                maximum[i] = a;
                maxS.erase(a);

            }else{
                auto temp = minS.lower_bound(1);
                minimal[i] = (*temp);
                minS.erase(temp);

                auto temp1 = maxS.lower_bound(prev);
                temp1--;
                maximum[i] = *temp1;
                maxS.erase(temp1);
            }
        }
        for (int i = 0; i < n; ++i) {
            cout<<minimal[i]<<" ";
        }
        cout<<"\n";
        for (int i = 0; i < n; ++i) {
            cout<<maximum[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}