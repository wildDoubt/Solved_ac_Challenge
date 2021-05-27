// 25분

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

int arr[100005];

int main(){
    Quick_IO();
    int N, M;
    cin>>N>>M;
    for (int i = 0; i < N; ++i) {
        cin>>arr[i];
    }
    int lo = 0;
    int hi = 1000000000;
    int answer = INF;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        int counts = 1;
        ll temp = 0;
        for (int i = 0; i < N; ++i) {
            if(mid<arr[i]){
                // 블루레이의 크기가 레슨의 길이보다 작은 경우는 제외해줘야 한다.
                counts = INF;
            }
            temp += arr[i];
            if(temp>mid){
                counts++;
                temp = arr[i];
            }
        }
        if(counts>M){
            lo = mid+1;
        }else{
            answer = min(answer, mid);
            hi = mid-1;
        }
    }
    cout<<answer<<"\n";

    return 0;
}