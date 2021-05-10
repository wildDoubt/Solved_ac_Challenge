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
int cube[21];
int main(){
    Quick_IO();
    int length, width, height;
    cin>>length>>width>>height;
    int N;
    cin>>N;
    for(int i = 0;i<N;i++){
        int a, b;
        cin>>a>>b;
        cube[a] = b;
    }


    return 0;
}