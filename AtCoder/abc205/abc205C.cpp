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

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    Quick_IO();
    ll A, B, C;
    cin>>A>>B>>C;
    if(C%2==0){
        if(abs(A)>abs(B)){
            cout<<">\n";
        }else if(abs(A)<abs(B)){
            cout<<"<\n";
        }else{
            cout<<"=\n";
        }
    }else{
        int d1 = 1;
        int d2 = 1;
        if(A<0) d1 = -1;
        if(B<0) d2 = -1;
        if(abs(A)*d1>abs(B)*d2){
            cout<<">\n";
        }else if(abs(A)*d1<abs(B)*d2){
            cout<<"<\n";
        }else{
            cout<<"=\n";
        }
    }

    return 0;
}