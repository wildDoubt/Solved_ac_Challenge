#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>
#include <sstream>

using namespace std;
using p = pair<int, int>;
using ll = long long;
const int MAX = 10e+6;
const int INF = 0x66554433;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    Quick_IO();
    int N;
    cin>>N;
    set<int> s;
    bool flag = true;
    for (int i = 0; i < N; ++i) {
        int a;
        cin>>a;
        if(s.count(a)==0)
            s.insert(a);
        else{
            flag = false;
            break;
        }
    }
    if(flag){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    cout<<"\n";

    return 0;
}