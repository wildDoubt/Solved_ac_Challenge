#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>

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

vector<p> coord;

int main(){
    Quick_IO();
    int N;
    cin>>N;
    while(N--){
        int a, b;
        cin>>a>>b;
        coord.emplace_back(a, b);
    }
    sort(coord.begin(), coord.end(), [](p a, p b){
        if(a.second==b.second) return a.first<b.first;
        return a.second<b.second;
    });
    for (const auto& x:coord) cout<<x.first<<" "<<x.second<<"\n";
    return 0;
}