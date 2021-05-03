#include <iostream>
#include <algorithm>

using namespace std;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    Quick_IO();
    int a, b;
    cin>>a>>b;
    if(a>b) cout<<">\n";
    else if(a<b) cout<<"<\n";
    else cout<<"==";
    return 0;
}