#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using p = pair<int, int>;

const int INF = 0x66554433;
const int MAX = 1e6 + 5;

inline void quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int arr[200005];
struct compare{
    bool operator()(ll a, ll b){
        return a>b;
    }
};
int main() {
    quick_IO();
    int n;
    cin >> n;
    vector<ll> negative;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    priority_queue<ll, vector<ll>, compare> answer;
    ll temp = 0;
    for (int i = 0; i < n; ++i) {
        answer.push(arr[i]);
        temp+=arr[i];
        if(temp<0){
            temp-=answer.top();
            answer.pop();
        }
    }
    cout<<answer.size()<<"\n";
    return 0;
}