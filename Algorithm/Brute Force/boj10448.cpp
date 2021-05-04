#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>

using namespace std;

const int MAX = 10e+6;
const int INF = 0x66554433;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    Quick_IO();
    int t;
    int num = 1;
    int j = 2;
    vector<int> tri;
    while(num<1000){
        tri.push_back(num);
        num+=(j++);
    }
    function<bool(int)> check = [&tri](int n){
        int r = lower_bound(tri.begin(), tri.end(), n) - tri.begin();
        for (int i = 0; i < r; ++i) {
            for (int k = 0; k <r; ++k) {
                for (int l = 0; l < r; ++l) {
                    if(n == tri[i] + tri[k] + tri[l]) return true;
                }
            }
        }
        return false;
    };
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(check(n)) cout<<1<<"\n";
        else cout<<0<<"\n";
    }

    return 0;
}


