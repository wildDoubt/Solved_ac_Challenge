#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using p = pair<int, int>;

const int INF = 0x66554433;

inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll calc(int n){
    ll a = 0;
    while(n--){
        a += ((n*(n+1))>>1);
    }
    return a;
}
int temp[100001];
ll dp[100001];
ll rdp[100001];
ll pdp[100001];
int main(){
    quick_IO();
    int t;
    cin>>t;
    while(t--){
        int n;
        map<ll, ll> arr;

        cin>>n;
        ll answer = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin>>a;
            temp[i] = a;
        }

        for (int i = 0; i < n; ++i) {
            if(i>0) dp[i] = dp[i-1];
            if(arr.count(temp[i])){
                dp[i]+=arr[temp[i]];
            }
            arr[temp[i]] += (i+1);
            answer += dp[i];
        }

        for (int i = 0; i < n; ++i) {
            cout<<dp[i]<<" ";
        }
        cout<<endl;
        cout<<answer<<endl;
    }
    return 0;
}