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
        int k;
        cin>>k;
        int e = 1;
        int w = 0;
        int counts = 1;
        while((100-k)*e!=k*w){
            if((100-k)*e<k*w){
                e++;
                counts++;
            }else if((100-k)*e>k*w){
                w++;
                counts++;
            }else{
                break;
            }
        }
        cout<<counts<<"\n";
    }
    return 0;
}