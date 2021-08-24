#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 2001;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int arr[MAX];
int dp[MAX][MAX];

bool isPalindrome(int start, int end){
    int &ret = dp[start][end];
    if(ret!=-1) return ret;
    if(start>=end) return true;
    if(arr[start]!=arr[end]) return ret = false;
    return ret = isPalindrome(start+1, end-1);
}

int main() {
    Quick_IO();
    memset(dp, -1, sizeof(dp));
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];

    int M;
    cin >> M;
    for (int i = 0, s, e; i < M; ++i) {
        cin >> s >> e;
        s--;
        e--;

        cout << isPalindrome(s, e) << '\n';
    }
    return 0;
}