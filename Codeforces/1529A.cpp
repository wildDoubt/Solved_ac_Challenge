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

int main(){
    quick_IO();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[101];
        fill(arr, arr+101, 0);
        set<int> s;
        for (int i = 1; i <= n; ++i) {
            int a;
            cin>>a;
            arr[a]++;
            s.insert(a);
        }
        int total = 0;
        int c = 0;
        for (auto x: s) {
            total+=x;
            c++;
        }
        for (int i = total/c+1; i < 101; ++i) {
            arr[i] = 0;
            s.erase(i);
        }


        for (int i = 1; i <= 100; ++i) {
            if(arr[i]>0) c++;
        }
        cout<<"answer: "<<c<<"\n";

    }
    return 0;
}