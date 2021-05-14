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

ll arr[100005];

ll calc(int left, int right){
    if(left==right){
        return 0;
    }
    if(left + 1 == right){
        return arr[left]*arr[left];
    }
    int mid = (left + right)/2;

    ll result = max(calc(left, mid), calc(mid, right));
    int l = mid, r = mid;
    ll minValue = min(arr[l], arr[r]);
    ll sum = arr[l];
    while(r-l+1<right-left){
        ll leftMin =l>left? min(minValue, arr[l-1]):-1;
        ll rightMin =r<right-1? min(minValue, arr[r+1]):-1;
        ll leftSum = sum+arr[l-1];
        ll rightSum = sum+arr[r+1];
        if(leftMin*leftSum>=rightMin*rightSum){
            // 왼쪽으로 확장
            sum = leftSum;
            minValue = leftMin;
            l--;
        }else{
            // 오른쪽으로 확장
            sum = rightSum;
            minValue = rightMin;
            r++;
        }
        result = max(result, minValue*sum);
    }
    return result;
}
int main(){
    quick_IO();
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin>>a;
        arr[i] = a;
    }
    cout<<calc(0, n)<<"\n";
    return 0;
}