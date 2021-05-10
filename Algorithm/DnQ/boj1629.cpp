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
ll c;
ll calc(ll A, ll B){
    if(B==0){
        return 1%c;
    }
    if(B==1){
        return A%c;
    }
    if(B%2==0){
        ll a = calc(A, B/2);
        return a*a%c;
    }
    else{
        ll a = calc(A, B/2);
        return (a*a)%c*A%c;
    }
}
int main(){
    Quick_IO();
    ll A, B, C;
    cin>>A>>B>>C;
    c = C;
    cout<<calc(A, B)%c<<"\n";
    return 0;
}