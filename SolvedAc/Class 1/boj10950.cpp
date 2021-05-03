#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    Quick_IO();
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        cout<<a+b<<"\n";
    }

    return 0;
}