#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int INF = 2e9;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int maxValue = -INF;
string s;
int N;

int calc(int a, char op, int b){
    if(op=='*') return a*b;
    else if(op=='+') return a+b;
    else return a-b;
}

void solve(int left, int opIndex){
    if(opIndex>=(int)s.size()){
        maxValue = max(left, maxValue);
        return;
    }
    int res1 = calc(left, s[opIndex], s[opIndex+1]-'0');
    solve(res1, opIndex+2);
    if(opIndex+3<(int)s.size()){
        int temp = calc(s[opIndex+1]-'0', s[opIndex+2], s[opIndex+3]-'0');
        int res2 = calc(left, s[opIndex], temp);
        solve(res2, opIndex+4);
    }
}

int main(){
    Quick_IO();
    cin>>N>>s;
    solve(s[0]-'0', 1);
    cout<<maxValue<<"\n";

    return 0;
}