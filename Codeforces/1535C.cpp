#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>
#include <sstream>

using namespace std;
using p = pair<int, int>;
using ll = long long;
const int MAX = 10e+6;
const int INF = 0x66554433;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

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
        string s;
        cin>>s;
        int n = (int)s.size();
        ll dp[2][n+1];
        ll answer = 0;
        dp[0][0] = 0;
        dp[1][0] = 0;
        for (int i = 0; i < n; ++i) {
            if(s[i]=='1'){
                dp[0][i+1] = 0;
                dp[1][i+1] = dp[0][i]+1;
            }else if(s[i]=='0'){
                dp[0][i+1] = dp[1][i]+1;
                dp[1][i+1] = 0;
            }else{
                dp[0][i+1] = dp[1][i]+1;
                dp[1][i+1] = dp[0][i]+1;
            }
            answer+=max(dp[1][i+1], dp[0][i+1]);
        }
        cout<<answer<<"\n";
    }

    return 0;
}