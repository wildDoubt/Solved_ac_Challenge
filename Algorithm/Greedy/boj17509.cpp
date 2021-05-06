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

int main(){
    Quick_IO();
    int arr[11];
    int answer = 0;
    int v;
    for(int i = 0;i<11;i++){
        cin>>arr[i];
        cin>>v;
        answer += v*20;
    }
    sort(arr, arr+11, [](int a, int b){
        return a<b;
    });
    int pD = 0;
    for(int& x:arr) answer += pD += x;
    cout<<answer<<endl;
    return 0;
}