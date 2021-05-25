#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>
#include <map>
using namespace std;

const int MAX = 2e+7;
const int MIN = -1e+7;
inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int arr[MAX];

int main(){
    Quick_IO();
    int N, M;
    cin>>N;
    for (int i = 0; i < N; ++i) {
        int a;
        cin>>a;
        arr[a-MIN]++;
    }
    cin>>M;
    for (int i = 0; i < M; ++i) {
        int a;
        cin>>a;
        cout<<arr[a-MIN]<<" ";
    }
    cout<<"\n";
    return 0;
}