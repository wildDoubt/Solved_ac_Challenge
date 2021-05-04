#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

const int MAX = 10e+6;
const int INF = 0x66554433;
int arr[15][15];
inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    Quick_IO();

    for(int i = 1;i<=14;i++){
        arr[0][i] = i;
    }
    for(int i = 1;i<=14;i++){
        for(int j = 1;j<=14;j++){
            arr[i][j] = arr[i][j-1]+arr[i-1][j];
        }
    }
//    for (int i = 0; i < 14; ++i) {
//        for (int j = 0; j < 14; ++j) {
//            cout<<arr[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    int t;
    cin>>t;
    while(t--){
        int k, n;
        cin>>k>>n;
        cout<<arr[k][n]<<"\n";
    }

    return 0;
}