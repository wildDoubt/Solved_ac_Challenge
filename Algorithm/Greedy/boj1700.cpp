#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>
#include <map>

using namespace std;
using p = pair<int, int>;
using ll = long long;
const int MAX = 10e+6;
const int INF = 0x66554433;

// 남은 개수, 번호
vector<int> arr;
inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    Quick_IO();
    int N, K;
    cin>>N>>K;
    set<int> currSet;
    for (int i = 0; i < K; ++i) {
        int a;
        cin>>a;
        // currSet이 N개가 될 때까지 채워야 함.
        if(currSet.size()<N){
            currSet.insert(a);
        }
        arr.push_back(a);
    }

    int answer = 0;
    for (int i = N; i < K; ++i) {
        if(currSet.count(arr[i])){
            continue;
        }
        int maxValue = -1;
        int maxIndex = -1;
        for(auto x:currSet){
            auto d = find(arr.begin()+i+1, arr.end(), x);
            if(maxValue<d-arr.begin()){
                maxValue = d-arr.begin();
                maxIndex = x;
            }
        }
        currSet.erase(maxIndex);
        currSet.insert(arr[i]);
        answer++;
    }
    cout<<answer<<endl;
    return 0;
}