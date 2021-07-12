#define LOCAL

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
    int N, B, C;
    cin>>N;
    int arr[N];
    for (int i = 0; i < N; ++i) {
        cin>>arr[i];
    }
    cin>>B>>C;
    ll result = N;
    for (int i = 0; i < N; ++i) {
        arr[i]-=B;
        if(arr[i]<=0) continue;
        result+=(arr[i]/C);
        if(arr[i]%C!=0) result++;
    }
    cout<<result<<'\n';
    return 0;
}