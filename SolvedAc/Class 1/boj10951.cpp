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
    while(true){
        int a, b;
        cin>>a>>b;
        if(cin.eof()) break;
        cout<<a+b<<"\n";
    }
    return 0;
}