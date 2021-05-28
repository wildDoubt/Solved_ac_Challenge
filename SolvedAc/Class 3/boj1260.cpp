#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>
#include <stack>

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

vector<vector<int>> adj;
bool visited[1005];

int main(){
    Quick_IO();
    int N,M,V;
    cin>>N>>M>>V;
    adj.resize(N+1, vector<int>(N+1, 0));
    for (int i = 1; i <= M; ++i) {
        int u, v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    stack<int> s;
    queue<int> q;
    s.push(V);
    q.push(V);

    while(!s.empty()){
        int curr = s.top();
        if(!visited[curr]) cout<<curr<<" ";
        s.pop();
        visited[curr] = true;
        for (int i = (int)adj[curr].size()-1;i>=1;i--) {
            if(!visited[i]&&adj[curr][i]){
                s.push(i);
                //cout<<"s push "<<i<<endl;
            }
        }
    }
    cout<<"\n";
    fill(visited+1, visited+N+1, false);
    while(!q.empty()){
        int curr = q.front();
        if(!visited[curr]) cout<<curr<<" ";
        q.pop();
        visited[curr] = true;
        for (int i = 0;i<adj[curr].size();i++) {
            if(!visited[i]&&adj[curr][i]){
                q.push(i);
                //cout<<"q push "<<i<<endl;
            }
        }
    }
    return 0;
}