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

int arr[MAX+1];

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    Quick_IO();
    int n, k;
    cin>>n>>k;
    for (int i = 0; i < n; ++i) {
        cin>>arr[n-i-1];
    }
    int answer = 0;

    for (int i = 0; i < n; ++i) {
        if(k==0) break;
        if(arr[i]>k) continue;
        int d = k/arr[i];
        answer += d;
        k-=d*arr[i];
    }
    cout<<answer<<"\n";
    return 0;
}