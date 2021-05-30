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

const int INF = 0x66554433;
ll arr[100001];
ll dp[100001];

inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


int main(){
    quick_IO();
    int n;
    int i, j, k;
    cin>>n;
    int temp;
    int maxValue = -1;
    for(i=0;i<n;i++){
        cin>>temp;
        maxValue = max(temp, maxValue);
        arr[temp]++;
    }
    dp[1] = arr[1];
    for(i=2;i<=maxValue;i++){
        dp[i] = max(dp[i-2]+arr[i]*i, dp[i-1]);
    }
    cout<<dp[maxValue]<<"\n";
    return 0;
}