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
    int n, total = 0;
    for (int i = 0; i < 5; ++i) {
        cin>>n;
        total += pow(n, 2);
    }
    cout<<total%10<<"\n";
    return 0;
}