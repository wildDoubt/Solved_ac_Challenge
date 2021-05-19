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

vector<string> arr;
bool check[101];
int main(){
    quick_IO();
    string S;
    int n;
    cin>>S>>n;
    for (int i = 0; i < n; ++i) {
        string a;
        cin>>a;
        arr.push_back(a);
    }
    check[S.size()] = true;
    for (int i = S.size()-1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if((i+arr[j].size()<=S.size())&&(check[i+arr[j].size()])&&(S.substr(i, arr[j].size())==arr[j])){
                check[i] = true;
            }
        }
    }
    cout<<check[0]<<"\n";
    return 0;
}