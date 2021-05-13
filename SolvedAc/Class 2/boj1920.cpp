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
set<int> check;
int main(){
    Quick_IO();
    int N, M;
    cin>>N;
    for(int i = 0;i<N;i++){
        int a;
        cin>>a;
        check.insert(a);
    }
    cin>>M;
    for(int i = 0;i<M;i++){
        int a;
        cin>>a;
        if(check.count(a)) cout<<"1\n";
        else cout<<"0\n";
    }

    return 0;
}