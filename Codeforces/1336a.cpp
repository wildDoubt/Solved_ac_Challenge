#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

using ll = long long;

const int MAX = 200005;
vector<int> adj[MAX];

priority_queue<int> pq;
inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int dfs(int currNode, int prevNode, int level){
    int child = 0;
    for(auto x:adj[currNode]){
        if(x!=prevNode){
             child += dfs(x, currNode, level+1) + 1;
        }
    }
    pq.push(level - child);
    return child;
}

int main(){
    quick_IO();
    int n, counts;
    int i;
    int a, b;

    cin>>n>>counts;

    for(i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1, 0);
    ll answer = 0;
    for(i=0;i<counts;i++){
        answer += pq.top();
        pq.pop();
    }
    cout<<answer<<"\n";
    return 0;
}