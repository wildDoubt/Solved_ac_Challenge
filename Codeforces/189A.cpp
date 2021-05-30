#include <bits/stdc++.h>
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

const int INF = 800000;

int n, a, b, c;
int dp[4005];

inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    quick_IO();
    cin>>n>>a>>b>>c;
    vector<int> length = {a, b, c};
    sort(length.begin(), length.end());
    int i, j, k;

    for(i=0;i<=n;i++){
        for(j=0;j<3;j++){
            if(i%length[j]==0){
                dp[i] = max(dp[i], i/length[j]);
            }
            else{
                if(dp[i]>0&&i+length[j]<=n){
                    dp[i+length[j]] = max(dp[i]+1, dp[i+length[j]]);
                }
            }
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}