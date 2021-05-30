#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <functional>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using p = pair<int, int>;

const int INF = 0x66554433;
const int MAX = 100000;
bool polluted[MAX+1];
vector<int> adj[MAX+1];
int dist[3][MAX+1];
int maxDistance = -1;
int furthestNode = 1;
inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    quick_IO();

    int n, m, d;
    int i, j, k;
    int startNode;
    int answer = 0;

    cin>>n>>m>>d;
    for(i=1;i<=m;i++){
        cin>>j;
        polluted[j] = true;
    }
//    startNode = j;
//    furthestNode = j;
    for(i=1;i<=n-1;i++){
        cin>>j>>k;
        adj[j].push_back(k);
        adj[k].push_back(j);
    }
    function<void(int, int, int)> dfs;
    function<void(int, int, int)> dfs1;
    function<void(int, int, int)> dfs2;
    dfs = [&dfs](int prevNode, int currNode, int level){
        dist[0][currNode] = level;
        for(auto x:adj[currNode]){
            if(x!=prevNode) dfs(currNode, x, level+1);
        }
    };
    dfs(-1, 1, 0);
    int temp = -1;
    for(i = 1;i<=n;i++){
        if(polluted[i]&&temp<dist[0][i]){
            temp = dist[0][i];
            startNode = i;
        }
    }
    dfs1 = [&dfs1](int prevNode, int currNode, int level){
        // cout<<currNode<<endl;
        dist[1][currNode] = level;
        if(polluted[currNode] && maxDistance<=level){
            maxDistance = level;
            furthestNode = currNode;
        }
        for(auto x:adj[currNode]){
            if(x!=prevNode) dfs1(currNode, x, level+1);
        }
    };
    dfs1(-1, startNode, 0); // maxDistance, furthestNode 찾음.
//    cout<<maxDistance<<" "<<furthestNode<<endl;
    dfs2 = [&dfs2](int prevNode, int currNode, int level){
        // cout<<currNode<<endl;
        dist[2][currNode] = level;
        for(auto x:adj[currNode]){
            if(x!=prevNode) dfs2(currNode, x, level+1);
        }
    };
    dfs2(-1, furthestNode, 0);
//    for(i = 1;i<=n;i++) cout<<dist[0][i]<<" ";
//    cout<<endl;
//    for(i = 1;i<=n;i++) cout<<dist[1][i]<<" ";
    for(i=1;i<=n;i++){
        if(dist[1][i]<=d && dist[2][i]<=d) answer++;
    }
//    cout<<endl;
    cout<<answer<<"\n";
    return 0;
}