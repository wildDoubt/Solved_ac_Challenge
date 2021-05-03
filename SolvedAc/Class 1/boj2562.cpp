#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    Quick_IO();
    int a, maxValue = -1, maxIndex = 0;
    for (int i = 1; i <= 9; ++i) {
        cin>>a;
        if(a>maxValue){
            maxValue = a;
            maxIndex = i;
        }
    }
    cout<<maxValue<<"\n"<<maxIndex<<"\n";
    return 0;
}