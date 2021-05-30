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
        int n, m;
        int sym = 0;
        cin>>n>>m;
        int a, b, c, d;
        for(int i = 0;i<n;i++){
            cin>>a>>b>>c>>d;
            if(b==c) sym++;
        }
        if(m%2==1) cout<<"NO\n";
        else{
            if(sym>0) cout<<"YES\n";
            else cout<<"NO\n";
        }

    }
    return 0;
}