#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>

using namespace std;
using p = pair<int, int>;
using ll = long long;
const int MAX = 10e+6;
const int INF = 0x66554433;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<p> adj[1005];
vector<p> radj[1005];
int dist[1005];
int rdist[1005];
int N, M, X;

void dij(int start){
    vector<bool> visited(N+1, false);

    priority_queue<p, vector<p>, greater<>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        int curr;
        do{
            curr = pq.top().second;
            pq.pop();
        }while(!pq.empty() && visited[curr]);
        if(visited[curr]) continue;
        for (auto &x: adj[curr]) {
            int nextIndex = x.first;
            int nextDist = x.second;
            if(dist[nextIndex]>nextDist+dist[curr]){
                dist[nextIndex] = nextDist+dist[curr];
                pq.push({dist[nextIndex], nextIndex});
            }
        }
    }
}
void rdij(int start){
    vector<bool> visited(N+1, false);

    priority_queue<p, vector<p>, greater<>> pq;
    pq.push({0, start});
    rdist[start] = 0;
    while(!pq.empty()){
        int curr;
        do{
            curr = pq.top().second;
            pq.pop();
        }while(!pq.empty() && visited[curr]);
        if(visited[curr]) continue;
        for (auto &x: radj[curr]) {
            int nextIndex = x.first;
            int nextDist = x.second;
            if(rdist[nextIndex]>nextDist+rdist[curr]){
                rdist[nextIndex] = nextDist+rdist[curr];
                pq.push({rdist[nextIndex], nextIndex});
            }
        }
    }
}

int main(){
    Quick_IO();
    cin>>N>>M>>X;
    fill(dist+1, dist+N+1, INF);
    fill(rdist+1, rdist+N+1, INF);
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v, w);
        radj[v].emplace_back(u, w);
    }
    dij(X);
    rdij(X);
    int answer = -INF;
    for (int i = 1; i <= N; ++i) {
        answer = max(answer, dist[i]+rdist[i]);
    }
    cout<<answer<<"\n";
    return 0;
}