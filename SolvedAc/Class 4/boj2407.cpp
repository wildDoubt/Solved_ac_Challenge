#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

string dp[101][101];
string add(string a, string b){
    string res;
    int temp = 0;
    while(!a.empty()||!b.empty()||temp!=0){
        int currA = a.empty()?0:a.back()-'0';
        int currB = b.empty()?0:b.back()-'0';
        int c = (currA+currB+temp)/10;
        int s = (currA+currB+temp)%10;
        res += to_string(s);
        temp = c;
        if(!a.empty()) a = a.substr(0, (int)a.size()-1);
        if(!b.empty()) b = b.substr(0, (int)b.size()-1);
    }

    reverse(res.begin(), res.end());
    return res;
}
string calc(int n, int m){
    if(dp[n][m]!="-1") return dp[n][m];
    if(m==0||m==n) return dp[n][m] = "1";
    return dp[n][m] = add(calc(n-1, m-1), calc(n-1, m));
}

int main(){
    Quick_IO();
    int N, M;
    cin>>N>>M;
    for (int i = 0; i <= N; ++i) {
        fill(dp[i], dp[i]+N+1, "-1");
    }
    cout<<calc(N, M)<<"\n";
    // cout<<add("52", "98");
    return 0;
}