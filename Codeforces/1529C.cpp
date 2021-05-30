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
const int MAX = 2e5 + 5;
inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

p arr[MAX+1];
vector<int> adj[MAX+1];
ll dp[2][MAX+1];
bool visited[MAX+1];
void dfs(int prev, int curr){
    dp[0][curr] = dp[1][curr] = 0;
    visited[curr] = true;
    for (auto x:adj[curr]) {
        if(!visited[x]){
            dfs(curr, x);
            dp[0][curr] += max(dp[0][x] + abs(arr[curr].first - arr[x].first),
                               dp[1][x] + abs(arr[curr].first - arr[x].second));
            dp[1][curr] += max(dp[1][x] + abs(arr[x].second - arr[curr].second),
                               dp[0][x] + abs(arr[x].first - arr[curr].second));
        }
    }
}

void init(int n){
    fill(visited, visited+n+1, false);
    for (int i = 0; i < n+1; ++i) {
        adj[i].clear();
    }
}

int main(){
    quick_IO();
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        for (int i = 1; i <= N; ++i) {
            int a, b;
            cin>>a>>b;
            arr[i] = p(a, b);
        }
        for (int i = 0; i < N-1; ++i) {
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, 1);
        cout<<max(dp[0][1], dp[1][1])<<"\n";
        init(N);
    }
    return 0;
}