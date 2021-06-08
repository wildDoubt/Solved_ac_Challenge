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

int dp[4001][4001];

int main(){
    Quick_IO();
    string a, b;
    cin>>a>>b;
    a = " "+a;
    b = " "+b;
    int answer = 0;
    for (int i = 1; i < (int)a.size(); ++i) {
        for (int j = 1; j < (int)b.size(); ++j) {
            if(a[i]==b[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
                answer = max(answer, dp[i][j]);
            }else{
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < (int)a.size(); ++i) {
        for (int j = 1; j < (int)b.size(); ++j) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<answer<<"\n";

    return 0;
}