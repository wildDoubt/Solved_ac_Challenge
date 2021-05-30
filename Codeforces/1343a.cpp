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
int arr[200005];
vector<ll> low;
vector<ll> high;
map<int, int> noChange;
int answer = INF;
int main(){
    quick_IO();
    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k;
        for(int i = 1;i<=n;i++){
            cin>>arr[i];
        }
        for(int i = 1;i<=n/2;i++){
            noChange[arr[i]+arr[n-i+1]]++;
            high.push_back(max(arr[i], arr[n-i+1]) + k);
            low.push_back(min(arr[i], arr[n-i+1]) + 1);
        }
        sort(low.begin(), low.end());
        sort(high.begin(), high.end());
        // x의 범위는 1~2*k

        for (int x = 1; x <= 2*k; ++x) {
            int a = upper_bound(low.begin(), low.end(), x) - low.begin(); // low가 x 이하인 개수
            int b = high.end() - lower_bound(high.begin(), high.end(), x); // high가 x 이상인 개수

            int A = min(a, b); // 두 값 중 최소값이 x를 완전히 포함하는 범위의 개수
            answer = min(answer, A - noChange[x] + 2*(n/2-A));
        }
        low.clear();
        high.clear();
        noChange.clear();
        cout<<answer<<endl;
        answer = INF;
    }
    return 0;
}