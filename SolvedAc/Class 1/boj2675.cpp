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
        int r;
        string a;
        cin>>r>>a;
        for(auto x:a){
            for (int i = 0; i < r; ++i) {
                cout<<x;
            }
        }
        cout<<"\n";
    }
    return 0;
}