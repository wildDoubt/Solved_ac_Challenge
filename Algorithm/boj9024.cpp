#include <bits/stdc++.h>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
long long calc(const int arr[], int left, int right, int value){
    long long answer = 0;
    while(left<right){
        int temp_sum = arr[left]+arr[right];
        if(temp_sum==value){
            answer++;
            left++;
            right--;
        }else if(temp_sum>value){
            right--;
        }else{
            left++;
        }
    }
    return answer;
}

int main() {
    Quick_IO();
    int T;
    cin>>T;
    while(T--){
        int n, k;
        cin>>n>>k;
        int arr[n];
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
        }
        sort(arr, arr+n);
        int l=0,r=n-1;
        int x = 2100000000;
        int xValue = abs(x-k);
        while(l<r){
            int temp_sum = arr[l]+arr[r];
            if(abs(temp_sum-k)<xValue){
                xValue = abs(temp_sum-k);
                x = temp_sum;
            }
            if(temp_sum==k){
                x = k;
                break;
            }else if(temp_sum>k){
                r--;
            }else{
                l++;
            }
        }
        if(xValue!=0){
            cout<<calc(arr, 0, n-1, k-xValue)+calc(arr, 0, n-1, k+xValue)<<"\n";
        }else{
            cout<<calc(arr, 0, n-1, k)<<"\n";
        }
    }
}