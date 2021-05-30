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

vector<int> check;

int main(){
    quick_IO();
    int t;
    cin>>t;
    while(t--){
        int n, k;
        string s;
        cin>>n>>k;
        cin>>s;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i]=='*') check.push_back(i);
        }
        int counts = 0;
        if(check.size()<=2){
            counts = check.size();
        }else{
            int prev = check[0];

            for (int i = 1; i < check.size()-1; ++i) {
                if(check[i+1]-prev>k){
                    counts++;
                    prev = check[i];
                }
            }
            counts+=2;
        }
        cout<<counts<<"\n";
        check.clear();
    }
    return 0;
}