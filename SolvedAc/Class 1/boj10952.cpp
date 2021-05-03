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
    int a, b;
    while(true){
        cin>>a>>b;
        if(!a&&!b) break;
        cout<<a+b<<"\n";
    }
    return 0;
}