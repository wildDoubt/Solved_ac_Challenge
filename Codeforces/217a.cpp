
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

int X[100];
int Y[100];
bool visited[100];
int n;
int dfs(int t){
    visited[t] = true;
    for(int i = 0;i<n;i++){
        if(!visited[i]&&(X[i]==X[t]||Y[i]==Y[t])){
            dfs(i);
        }
    }
}

int main(){
    quick_IO();
    int x, y;
    cin>>n;
    int counts = 0;
    for (int i = 0; i < n; ++i) {
        cin>>x>>y;
        X[i] = x;
        Y[i] = y;
    }
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            dfs(i);
            counts++;
        }
    }
    cout<<counts-1<<"\n";
    return 0;
}