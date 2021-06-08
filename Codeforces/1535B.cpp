#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>
#include <sstream>
#include <numeric>

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
        int n;
        cin>>n;
        vector<int> arr;

        for(int i = 0;i<n;i++){
            int a;
            cin>>a;
            if(a%2==1) arr.push_back(a);
        }
        sort(arr.begin(), arr.end(), [](int a, int b){
            return a>b;
        });
        int counts=0;
        for (int i = 0; i < (int)arr.size(); ++i) {
            for (int j = i+1; j < (int)arr.size(); ++j) {
                if(gcd(arr[i], 2*arr[j])==1){
                    counts++;
                }
            }
        }
        cout<<(n*(n-1))/2-counts<<"\n";
    }
    return 0;
}