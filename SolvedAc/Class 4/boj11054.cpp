#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 0x66554433;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int arr[1005];
int rarr[1005];
int dp[1005];
int rdp[1005];

int main(){
    Quick_IO();
    int N;
    cin>>N;
    for (int i = 0; i < N; ++i) {
        cin>>arr[i];
        rarr[N-1-i] = arr[i];
    }
    fill(dp, dp+N+1, 1);
    fill(rdp, rdp+N+1, 1);
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if(rarr[i]>rarr[j]){
                rdp[i] = max(rdp[i], rdp[j]+1);
            }
        }
    }

    int answer = -INF;
    for (int i = 0; i < N; ++i) {
        answer = max(answer, dp[i]+rdp[N-1-i]);
    }
    cout<<answer-1<<"\n";
    return 0;
}