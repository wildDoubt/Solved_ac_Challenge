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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll arr[n];
        ll total = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            total+=arr[i];
        }
        if(total%n!=0){
            cout<<-1<<'\n';
        }else{
            ll avg = total/n;
            int counts = 0;
            for (int i = 0; i < n; ++i) {
                if(arr[i]-avg>0) counts++;
            }
            cout<<counts<<'\n';
        }
    }

    return 0;
}