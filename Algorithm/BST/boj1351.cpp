#include <iostream>
#include <unordered_map>

using namespace std;
using ll = long long;

ll N, P, Q;
unordered_map<ll, ll> M;

ll calc(ll num){
    ll &ret = M[num];
    if(num==0) return 1;
    if(ret>0) return ret;
    return ret = calc(num/P) + calc(num/Q);
}

int main() {
    cin>>N>>P>>Q;
    cout<<calc(N)<<'\n';

    return 0;
}