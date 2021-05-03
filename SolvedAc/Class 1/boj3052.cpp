#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;
bool check[42];
inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    Quick_IO();
    int a, counts = 0;
    for (int i = 0; i < 10; ++i) {
        cin>>a;
        check[a%42] = true;
    }
    for (bool c : check) {
        if(c) counts++;
    }
    cout<<counts<<"\n";
    return 0;
}