#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>

using namespace std;

const int MAX = 10e+6;
const int INF = 0x66554433;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    Quick_IO();
    int t = 0;
    int L, P, V;
    while(true){
        cin>>L>>P>>V;
        if(L==0&&P==0&&V==0) break;
        cout<<"Case "<<++t<<": "<<V/P*L + min(V%P, L)<<endl;
    }

    return 0;
}