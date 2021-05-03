#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    Quick_IO();
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            cout<<" ";
        }
        for (int j = n - i - 1; j < n; ++j) {
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}