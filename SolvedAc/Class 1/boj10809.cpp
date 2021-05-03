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
    int check[26];
    string a;
    fill(check, check+26, -1);
    cin>>a;
    for (int i = 0; i < a.size(); ++i) {
        if(check[a[i]-'a']==-1) check[a[i]-'a'] = i;
    }
    for(auto x:check) cout<<x<<" ";
    cout<<"\n";
    return 0;
}