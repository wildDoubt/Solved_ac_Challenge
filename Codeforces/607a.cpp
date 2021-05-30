#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

using p = pair<int, int>;

const int MAX = 1000000;
vector<p> arr;
int dp[MAX+1];

inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool comp(const p& a, const p& b){
    return a.first < b.first;
}

int main(){
    quick_IO();
    int n;
    cin>>n;
    arr.resize(n);
    int i;
    int position, power;
    for(i=0;i<n;i++) {
        cin>>position>>power;
        arr[i] = p(position, power);
    }
    sort(arr.begin(), arr.end(), comp);
    // for(i=0;i<n;i++) cout<<arr[i].first<<" "<<arr[i].second<<endl;
    dp[0] = 1;
    for(i=1;i<n;i++){
        auto it = lower_bound(arr.begin(), arr.begin()+i, p(arr[i].first-arr[i].second, 0), comp);
        int num = distance(it, arr.begin()+i);
        dp[i] = dp[i - (num + 1)] + 1;
    }
    // for(i=0;i<n;i++) cout<<dp[i]<<" ";
    cout<<n-*max_element(dp, dp+n)<<"\n";
    return 0;
}
// 첫 제출은 sort안하고 upper bound를 사용해서 틀렸음.
// sort 해야함.
// pair에서 upper bound 사용하는 법