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
bool checks[10];
int main(){
    Quick_IO();
    int N, M;
    cin>>N>>M;
    for (int i = 0; i < M; ++i) {
        int a;
        cin>>a;
        checks[a] = true;
    }
    function<bool(int)> calc = [](int num){
        string t = to_string(num);
        return all_of(t.begin(), t.end(), [](char i){return checks[i-'0'];});
        for(auto x:t){
            if(checks[x-'0']) return false;
        }
        return true;
    };
    int answer = abs(N-100);
    for(int i = 0;i<=1000000;i++){
        if(calc(i)){
            answer = min(answer, (int)to_string(i).length() + abs(N-i));
        }
    }
    cout<<answer<<"\n";
    return 0;
}