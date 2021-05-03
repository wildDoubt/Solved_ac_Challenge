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
    int n, totalSum = 0;
    string a;
    cin>>n;
    cin>>a;
    for(auto c:a){
        totalSum += (c-'0');
    }
    cout<<totalSum<<"\n";
    return 0;
}