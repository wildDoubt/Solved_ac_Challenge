#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>
#include <sstream>

using namespace std;
using p = pair<int, int>;
using ll = long long;
const int MAX = 2e5+1;

int parent[MAX];
int ranks[MAX];

int find(int a){
    if(parent[a]==a) return a;
    else{
        return parent[a] = find(parent[a]);
    }
}

void _union(int a, int b){
    int x = find(a);
    int y = find(b);

    if(x==y) return;

    if(ranks[x]>ranks[y]) {
        swap(x, y);
    }
    parent[x] = y;
    if(ranks[x]==ranks[y]) {
        ranks[y]++;
    }
}

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    Quick_IO();
    int N;
    cin>>N;
    int arr[N];
    set<int> counts;
    for (int i = 0; i < MAX; ++i) {
        parent[i] = i;
    }
    for(auto& x:arr){
        cin>>x;
    }
    int result = 0;
    for (int i = 0; i < N/2; ++i) {
        if(find(arr[i])!=find(arr[N-i-1])){
            _union(arr[i], arr[N-i-1]);
            result++;
        }
    }
    cout<<result<<'\n';
    return 0;
}