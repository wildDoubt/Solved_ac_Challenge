// 행렬 곱 구현 참고
// https://docs.microsoft.com/en-us/cpp/parallel/amp/walkthrough-matrix-multiplication?view=msvc-160


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
const ll MOD = 1000000007;

using matrix =  vector<vector<ll>>;

matrix operator*(const matrix &a, const matrix &b){
    ll row = a.size();
    ll col = b[0].size();
    matrix result(row, vector<ll>(col));
    for (ll i = 0; i < row; ++i) {
        for (ll j = 0; j < col; ++j) {
            for (ll k = 0; k < a[0].size(); ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
            result[i][j] %= MOD;
        }
    }
    return result;
}

matrix calc(const matrix& a, ll n){
    if(n==0){
        matrix temp(a.size(), vector<ll>(a.size()));
        for (ll i = 0; i < a.size(); ++i) {
            temp[i][i] = 1;
        }
        return temp;
    }
    if(n%2==1){
        return calc(a, n-1)*a;
    }else{
        matrix temp = calc(a, n/2);
        return temp*temp;
    }
}

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(){
    Quick_IO();
    ll n;
    cin>>n;
    matrix m{{1, 1}, {1, 0}};
    cout<<calc(m, n)[0][1]<<"\n";

    return 0;
}