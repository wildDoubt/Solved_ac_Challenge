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
        int n;
        bool flag = false;
        cin>>n;
        while(n>0){
            if(n%111==0||n%11==0){
                flag = true;
                cout<<"YES\n";
                break;
            }
            n-=111;
        }

        if(!flag) cout<<"NO\n";
    }
    return 0;
}