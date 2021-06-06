#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <map>
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
        int n;
        cin>>n;
        map<string, int> map;
        for (int i = 0; i < n; ++i) {
            string a, b;
            cin>>a>>b;
            map[b]++;
        }
        int answer = 1;
        for(auto x:map){
            answer*=(x.second+1);
        }
        cout<<answer-1<<"\n";
    }

    return 0;
}