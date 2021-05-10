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
vector<p> arr;
bool check[1005];
int main(){
    Quick_IO();
    int N;
    int answer = 0;
    cin>>N;
    while(N--){
        int d, w;
        cin>>d>>w;
        arr.emplace_back(d, w);
    }

    sort(arr.begin(), arr.end(), [](p a, p b){
        if(a.second==b.second){
            return a.first>b.first;
        }
        return a.second>b.second;
    });
    for(auto & i : arr){
        int curr = i.first;
        while(check[curr]){
            curr--;
        }
        if(curr==0) continue;
        check[curr] = true;
        answer += i.second;
    }
    cout<<answer<<"\n";
    return 0;
}