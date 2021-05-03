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
    int H, M;
    int totalM;
    cin>>H>>M;
    totalM = H*60+M-45;
    if(totalM<0) totalM = 24*60+totalM;
    cout<<totalM/60<<" "<<totalM%60<<"\n";
    return 0;
}