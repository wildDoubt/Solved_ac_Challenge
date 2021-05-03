#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;
const int INF = 0x66554433;
inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    Quick_IO();
    int maxValue = -INF, minValue = INF;
    int n, a;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a;
        maxValue = max(maxValue, a);
        minValue = min(minValue, a);
    }
    cout<<minValue<<" "<<maxValue<<"\n";
    return 0;
}