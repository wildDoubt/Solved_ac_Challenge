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
int arr[10000];
priority_queue<int, vector<int>, greater<>> pq;
int main(){
    Quick_IO();
    int N, K;
    int answer = 0;
    cin>>N>>K;
    for (int i = 0; i < N; ++i) {
        cin>>arr[i];
    }
    sort(arr, arr+N);
    for(int i = 1;i<N;i++){
        pq.push(arr[i] - arr[i-1]);
    }
    int r = N - K;
    while(r--&&!pq.empty()){
        answer += pq.top();
        pq.pop();
    }
    cout<<answer<<"\n";
    return 0;
}