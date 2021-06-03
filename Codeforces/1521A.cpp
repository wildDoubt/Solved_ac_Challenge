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
        ll A, B;
        cin>>A>>B;
        if(B==1) cout<<"NO\n";
        else{
            ll x = A*B;
            ll y = (B+1)*A;
            ll z = x + y;
            cout<<"YES\n";
            cout<<x<<" "<<y<<" "<<z<<"\n";
        }
    }

    return 0;
}