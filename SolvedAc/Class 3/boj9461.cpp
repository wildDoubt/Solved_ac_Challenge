#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    Quick_IO();
    int t;
    cin>>t;
    ll P[101];
    P[1] = 1;
    P[2] = 1;
    P[3] = 1;
    P[4] = 2;
    P[5] = 2;
    for (int i = 6; i <= 100; ++i) {
        P[i] = P[i-1] + P[i-5];
    }
    while(t--){
        int N;
        cin>>N;
        cout<<P[N]<<"\n";
    }


    return 0;
}