#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>
#include <sstream>
#include <map>

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
    int N;
    cin>>N;
    int arr[N];
    for(auto& x:arr){
        cin>>x;
    }
    sort(arr, arr+N);
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        total += N - (upper_bound(arr, arr+N, arr[i]) - arr);
    }
    cout<<total<<'\n';
    return 0;
}