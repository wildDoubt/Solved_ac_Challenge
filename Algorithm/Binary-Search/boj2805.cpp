// 12분 57초

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

int arr[1000005];

int main(){
    Quick_IO();
    int N, M;
    cin>>N>>M;
    for (int i = 0; i < N; ++i) {
        cin>>arr[i];
    }
    int answer = -INF;
    int lo = 0;
    int hi = *max_element(arr, arr+N);

    while(lo<=hi){
        int mid = (lo+hi)/2;
        ll temp = 0;
        for (int i = 0; i < N; ++i) {
            temp += max(0, arr[i] - mid);
        }
        if(temp>=M){
            answer = max(answer, mid);
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    cout<<answer<<"\n";
    return 0;
}