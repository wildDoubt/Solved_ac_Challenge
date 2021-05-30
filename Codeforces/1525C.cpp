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
const int MAX = 1e6+5;

inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


int main(){
    quick_IO();
    int n;
    cin>>n;
    set<int> index0;
    set<int> index1;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        int a;
        cin>>a;
        if(a){
            index1.insert(i);
        }else{
            index0.insert(i);
        }
    }
    int counts = 0;
    for (auto i:index1) {
        int minValue = INF;
        int minIndex = INF;
        for (auto j:index0) {
            if(!visited[j]&&minValue>abs(j-i)){
                minValue = abs(j-i);
                minIndex = j;
            }
        }

        if(minValue!=INF) {
            counts += minValue;
        }
        if(minIndex!= INF) {
            visited[minIndex] = true;
        }
    }
    cout<<counts<<"\n";
    return 0;
}