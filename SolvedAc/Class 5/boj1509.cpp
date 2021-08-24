#include <iostream>
#include <cstring>

using namespace std;
using ll = long long;

const int MAX = 2501;
const int INF = 987654321;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

string s;
int dp[MAX][MAX];
ll pdp[MAX];

bool isPalindrome(int start, int end){
    int &ret = dp[start][end];
    if(ret!=-1) return ret;
    if(start>=end) return true;
    if(s[start]!=s[end]) return ret = false;
    return ret = isPalindrome(start+1, end-1);
}

int main() {
    Quick_IO();
    memset(dp, -1, sizeof(dp));
    memset(pdp, INF, sizeof(pdp));
    cin>>s;

    s=" "+s;
    pdp[0] = 0;
    int n = (int)s.size();
    for (int i = 1; i <= n; ++i) {
        pdp[i] = pdp[i-1] + 1ll;
        for (int j = 1; j < i; ++j) {
            if(!isPalindrome(j, i)) continue;

            pdp[i] = min(pdp[i], pdp[j-1] + 1ll);
        }
    }
    cout<<pdp[n-1]<<'\n';
    return 0;
}