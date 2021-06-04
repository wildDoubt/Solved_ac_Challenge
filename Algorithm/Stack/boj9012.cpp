#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>
#include <sstream>
#include <stack>

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
    int N;
    cin>>N;
    while(N--){
        string a;
        bool flag = true;
        cin>>a;
        stack<char> stack;
        for(char c:a){
            if(c=='('){
                stack.push(c);
            }else{
                if(stack.empty()){
                    flag = false;
                    break;
                }
                stack.pop();
            }
        }
        if(!flag||!stack.empty()){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }

    return 0;
}