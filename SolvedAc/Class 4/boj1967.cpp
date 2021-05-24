#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using p = pair<int, int>;

const int MAX = 10e+4;

vector<p> adj[MAX+1];
int dist[MAX+1];
bool visited[MAX+1];

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void dfs(int prev, int curr, int v){
    visited[curr] = true;
    for(auto x:adj[curr]){
        if(!visited[x.first]){
            visited[x.first] = false;
            dfs(curr, x.first, v+x.second);
            visited[x.first] = true;
        }
    }
    dist[curr] = v;
}

int main(){
    Quick_IO();
    int n;
    int a, b, c;
    cin>>n;
    for (int i = 0; i <n-1; ++i) {
        cin>>a>>b>>c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    dfs(0, 1, 0);
    int maxIndex = max_element(dist+1, dist+n+1) - dist;
    fill(visited+1, visited+n+1, false);
    dfs(0, maxIndex, 0);
    cout<<*max_element(dist+1, dist+n+1)<<endl;
    return 0;
}