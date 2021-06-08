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
    int N;
    cin>>N;
    vector<int> lis;
    for (int i = 0; i < N; ++i) {
        int a;
        cin>>a;
        auto it = lower_bound(lis.begin(), lis.end(), a);
        if(it==lis.end()){
            lis.push_back(a);
        }else{
            *it = a;
        }
    }
    cout<<lis.size()<<"\n";

    return 0;
}