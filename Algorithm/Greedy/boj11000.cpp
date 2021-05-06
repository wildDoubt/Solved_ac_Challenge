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
const int MAX = 200000;
const int INF = 0x66554433;

vector<p> arr;
priority_queue<int, vector<int>, greater<>> pq;
inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    Quick_IO();
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin>>a>>b;
        arr.emplace_back(a, b);
    }
    sort(arr.begin(), arr.end(), [](p a, p b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first<b.first;
    });
    pq.push(0);
    for(int i = 0;i<n;i++){
        if(pq.top()<=arr[i].first){
            // 추가
            pq.pop();
            pq.push(arr[i].second);
        }else{
            pq.push(arr[i].second);
        }
    }
    cout<<pq.size()<<"\n";
    return 0;
}