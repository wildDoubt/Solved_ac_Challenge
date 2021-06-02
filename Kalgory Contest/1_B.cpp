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

int arr[500005];

int main(){
    Quick_IO();
    int N;
    cin>>N;
    for (int i = 0; i < N; ++i) {
        cin>>arr[i];
    }
    sort(arr, arr+N);
    ll answer = 0;
    for (int i = 1; i <= N; ++i) {
        answer += abs(i-arr[i-1]);
    }
    cout<<answer<<"\n";

    return 0;
}