#include <iostream>
#include <algorithm>
#include <bitset>

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

int main(){
    Quick_IO();
    int N;
    cin>>N;
    bitset<26> dp;
    dp[0] = 1;
    int sum = 0;
    while(N--){
        int a;
        cin>>a;
        dp |= dp<<a;
        cout<<dp<<endl;
        sum+=a;
    }
    cout<<dp._Find_next((sum-1)/2)<<"\n";
    return 0;
}