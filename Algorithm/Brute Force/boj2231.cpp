#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

const int MAX = 10e+6;
const int INF = 0x66554433;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int getSum(int n){
    int dSum = n;
    while(n){
        dSum += n%10;
        n/=10;
    }
    return dSum;
}

int main(){
    Quick_IO();
    int n, i;
    cin>>n;
    for (i = 1; i < n; ++i) {
        if(getSum(i)==n) break;
    }
    if(i!=n) cout<<i<<"\n";
    else cout<<0<<"\n";
    return 0;
}