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
vector<p> arr;
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
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second<b.second;
    });
    int end = arr[0].second;
    int answer = 1;
    for (int i = 1; i < n; ++i) {
        if(end<=arr[i].first){
            end = arr[i].second;
            answer++;
        }
    }
    cout<<answer<<"\n";
    return 0;
}