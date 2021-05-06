#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>

using namespace std;

const int MAX = 10e+3;
const int INF = 0x66554433;
int arr[MAX+1];
inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    Quick_IO();
    int n, l;
    int answer = 1;
    cin>>n>>l;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    // sort input data
    sort(arr, arr+n);
    int start = arr[0];
    for(int i = 1;i<n;i++){
        if(start+l<=arr[i]){
            start = arr[i];
            answer++;
        }
    }
    cout<<answer<<"\n";
    return 0;
}