#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>
#include <sstream>
#include <unordered_map>
using namespace std;
using p = pair<int, int>;
using ll = long long;
const int MAX = 10e+6;
const int INF = 0x66554433;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}



int main() {
    Quick_IO();
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin>>n>>l>>r;
        int arr[n];
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
        }
        sort(arr, arr+n);
        ll answer1 = 0;
        ll answer2 = 0;

        int left = 0;
        int right = n-1;

        while(left<right){
            if(arr[left]+arr[right]<=r){
                answer1+= (right-left);
                left++;
            }else{
                right--;
            }
        }

        left = 0;
        right = n-1;

        while(left<right){
            if(arr[left]+arr[right]<l){
                answer2+= (right-left);
                left++;
            }else{
                right--;
            }
        }
        cout<<answer1-answer2<<'\n';
    }

    return 0;
}