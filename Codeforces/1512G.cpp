#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>

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

ll arr[100001];

int calc(int n){
    ll total = 0;
    for(int i = 1;i<=(int)sqrt(n);i++){
        if(n%i==0){
            total += i;
            total += (ll)n/i;
        }
    }
    arr[n] = total;
}

int main(){
    quick_IO();
    int t;
    int i, j;
    cin>>t;
    for(i=1;i<100001;i++){
        calc(i);
    }
    cout<<arr[100000]<<endl;
    while(t--){
        int c;
        cin>>c;
        auto it = find(arr, arr+7001, c);
        if(it!=(arr+7001)){
            cout<<distance(arr, it)<<"\n";
        }else{
            cout<<-1<<"\n";
        }

    }
    return 0;
}