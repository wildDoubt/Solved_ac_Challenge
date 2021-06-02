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
    ll X, Y, W, S;
    cin>>X>>Y>>W>>S;
    ll minValue = min(X, Y);
    ll maxValue = max(X, Y);
    vector<ll> answer;
    answer.push_back(minValue*S + (maxValue - minValue)*W);
    answer.push_back((X+Y)*W);
    if((X+Y)%2){
        answer.push_back((maxValue-1)*S+W);
    }else{
        answer.push_back((maxValue)*S);
    }
    cout<<*min_element(answer.begin(), answer.end())<<"\n";

    return 0;
}