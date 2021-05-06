#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    Quick_IO();
    // O(n^2)
    int arr[9];
    int total = 0;
    int i, j;
    bool flag = false;
    for (int & i : arr) {
        cin>>i;
        total += i;
    }
    sort(arr, arr+9);
    for (i = 0; i < 9; ++i) {
        for (j = i+1; j < 9; ++j) {
            if(total - arr[i] - arr[j]==100){
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    for(int k = 0;k<9;k++){
        if(k==i) continue;
        if(k==j) continue;
        cout<<arr[k]<<"\n";
    }
    return 0;
}