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


int main(){
    quick_IO();
    int t;
    cin>>t;
    while(t--){
        ll n, m, x;
        cin>>n>>m>>x;
        ll row, col;
        row = (x-1)%n;
        col = (x-1)/n;
        // cout<<row<<" "<<col<<endl;
        cout<<row*m+col+1<<endl;
    }
    return 0;
}