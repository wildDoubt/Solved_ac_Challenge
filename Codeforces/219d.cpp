#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
using p = pair<int, int>;

const int MAX = 200000;
vector<p> adj[MAX+1];
int dist[MAX+1];
int backOnNode[MAX+1];
int totalBack;
inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int dfs(int prevNode, int currNode, int level, int back){
    dist[currNode] = level;
    backOnNode[currNode] = back;
    int childBack = 0;
    for(auto x:adj[currNode]){
        if(x.first!=prevNode){
            if(x.second){
                childBack += dfs(currNode, x.first, level+1, back+1)+1;
            }else{
                childBack += dfs(currNode, x.first, level+1, back);
            }
        }
    }
    return childBack;
}
// 337d
int main(){
    quick_IO();
    int n;
    int i;
    cin>>n;
    int a, b;
    for(i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a].emplace_back(b, 0);
        adj[b].emplace_back(a, 1);
    }
    vector<p> answer;
    totalBack = dfs(-1, 1, 0, 0);
    for(i=1;i<=n;i++){
        answer.emplace_back(dist[i] - backOnNode[i] + (totalBack - backOnNode[i]), i);
    }
    sort(answer.begin(), answer.end(), less<>());
    int temp = answer[0].first;
    cout<<temp<<"\n";
    for(auto x:answer){
        if(temp!=x.first) break;
        cout<<x.second<<" ";
    }
    cout<<"\n";

    return 0;
}