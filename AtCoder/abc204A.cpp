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

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    Quick_IO();
    int x, y;
    cin>>x>>y;
    set<int> s{0, 1, 2};
    if(x==y){
        cout<<x<<"\n";
    }else{
        s.erase(x);
        s.erase(y);
        cout<<*s.begin()<<"\n";
    }

    return 0;
}