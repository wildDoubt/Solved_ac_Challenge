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
priority_queue<p> pq;
int main(){
    Quick_IO();
    int L, N, F, B;
    cin>>L>>N>>F>>B;
    ll d = F - B;
    for(int i = 0;i<N;i++){
        int x, c;
        cin>>x>>c;
        pq.push({c, x});
    }
    int lastIndex = 0;
    ll answer = 0;
    while(!pq.empty()){
        if(lastIndex<pq.top().second){
            answer += (pq.top().second - lastIndex)*d*pq.top().first;
            lastIndex = pq.top().second;
        }
        pq.pop();
    }

    cout<<answer<<"\n";
    return 0;
}