#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using p = pair<ll, ll>;

const ll INF = 100'000'000'000'000;

inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<p> adj[100005];
bool visited[100005];
ll dist[100005];
priority_queue<p, vector<p>, greater<p>> pq;
int prevIndex[100005];
stack<int> answer;
int main(){
    quick_IO();
    int n, m;
    int a, b, w;
    cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        cin>>a>>b>>w;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }
    fill(prevIndex+1, prevIndex+n+1, -1);
    pq.push({0, 1});
    fill(dist+1, dist+n+1, INF);
    dist[1] = 0;
    while(!pq.empty()){
        ll curr;
        do{
            curr = pq.top().second;
            pq.pop();
        }while(!pq.empty()&&visited[curr]);
        if(visited[curr]){
            break;
        }
        visited[curr] = true;
        for(auto x:adj[curr]){
            auto [nextIndex, nextWeight] = x;
            if(dist[nextIndex]>nextWeight+dist[curr]){
                prevIndex[nextIndex] = curr;
                dist[nextIndex] = nextWeight+dist[curr];
                pq.push({dist[nextIndex], nextIndex});
            }
        }
    }
    int searchIndex = n;

    while(searchIndex!=1){
        answer.push(searchIndex);
        if(searchIndex==-1){
            cout<<-1<<"\n";
            return 0;
        }
        // cout<<prevIndex[searchIndex]<<endl;
        searchIndex = prevIndex[searchIndex];
    }
    cout<<"1 ";
    while(!answer.empty()){
        cout<<answer.top()<<" ";
        answer.pop();
    }
    cout<<"\n";
    return 0;
}