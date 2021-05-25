#include <iostream>
#include <string>

const int MOD = 1234567891;
const int R = 31;

using namespace std;
using ll = long long;
int main(){
    int n;
    string s;
    cin>>n>>s;
    ll temp = 1ll;
    ll sum = 0ll;
    for (int i = 0; i < n; ++i) {
        sum = (sum + ((s[i]-'a'+1)*temp)%MOD)%MOD;
        temp = (temp*R)%MOD;
    }
    cout<<sum<<"\n";
    return 0;
}