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

int arr[105];
int pSum[105];

inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


int main(){
    quick_IO();
    int n;
    int i, j, k;
    int maxValue = -1;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>arr[i];
        pSum[i+1] = pSum[i] + arr[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<=n;j++){
            maxValue = max(pSum[n] - (pSum[j] - pSum[i]) + (j-i-(pSum[j] - pSum[i])), maxValue);
        }
    }
    cout<<maxValue<<endl;
    return 0;
}