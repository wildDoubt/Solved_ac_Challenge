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
        vector<int> S;
        for (int i = 0; i < 4; ++i) {
            int a;
            cin>>a;
            S.push_back(a);
        }
        int res1 = max(S[0], S[1]);
        int res2 = max(S[2], S[3]);

        sort(S.begin(), S.end());
        if((S[3]==res1&&S[2]==res2)||(S[3]==res2&&S[2]==res1)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }

    return 0;
}