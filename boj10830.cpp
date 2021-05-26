#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
using ll = long long;

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
            result[i][j] %= 1000;
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
    ll N, B;
    cin>>N>>B;
    matrix m(N, vector<ll>(N));
    for (ll i = 0; i < N; ++i) {
        for (ll j = 0; j < N; ++j) {
            cin>>m[i][j];
        }
    }
    matrix result = calc(m, B);
    for (const auto& row:result) {
        for(auto v:row){
            cout<<v<<" ";
        }
        cout<<"\n";
    }
    return 0;
}