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

ll arr[10000];
ll answer;
int N, K;
void getMaxLength(ll lo, ll hi){
    if(lo>hi) return;
    ll mid = (lo+hi)/2;
    ll temp = 0;
    for(int i = 0;i<K;i++){
        temp += arr[i]/mid;
    }
    if(temp>=N){
        answer = max(answer, mid);
        getMaxLength(mid+1, hi);
    }else{
        getMaxLength(lo, mid-1);
    }
}

int main(){
    Quick_IO();

    cin>>K>>N;
    ll hi = 0;
    for(int i = 0;i<K;i++){
        cin>>arr[i];
        hi = max(arr[i], hi);
    }
    getMaxLength(1, 1ll<<31);

    cout<<answer<<"\n";

    return 0;
}