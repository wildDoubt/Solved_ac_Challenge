// 5분 38초

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

int arr[10005];

int main(){
    Quick_IO();
    int N, M;
    cin>>N;
    for (int i = 0; i < N; ++i) {
        cin>>arr[i];
    }
    cin>>M;
    int lo = 0;
    int hi = *max_element(arr, arr+N);
    int answer = -INF;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        ll temp = 0;
        for (int i = 0; i < N; ++i) {
            temp += min(mid, arr[i]);
        }
        if(temp<=M){
            answer = max(mid, answer);
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    cout<<answer<<"\n";
    return 0;
}