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

vector<int> num;
int main(){
    quick_IO();
    int t;
    cin>>t;
    for(int i = 1;i<=9;i++){
        string a;
        // string(1, i-'0');
        for(int j = 0;j<=8;j++){
            // cout<<a<<" ";
            a+=string(1, i+'0');
            num.push_back(stoi(a));
        }
        cout<<endl;
    }
//    for(auto x:num){
//        cout<<x<<" ";
//    }
//    cout<<endl;
    sort(num.begin(), num.end());
    while(t--){
        int n;
        cin>>n;
        cout<<upper_bound(num.begin(), num.end(), n) - num.begin()<<endl;
    }
    return 0;
}