#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iomanip>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using p = pair<int, int>;
using ld = long double;

const int INF = 0x66554433;
const int MAX = 100000;
vector<int> adj[MAX+1];
bool visited[MAX+1];
inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ld dfs(int currNode, int prevNode){
    ld sum = 0;
    for(auto x:adj[currNode]){
        if(x!=prevNode){
            sum+=dfs(x, currNode) + 1;
        }
    }
    return sum? sum/(adj[currNode].size() - (prevNode!=-1)):0;
}

int main(){
    quick_IO();
    int n;
    int i, j, k;
    cin>>n;
    int a, b;
    for(i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<fixed<<setprecision(7)<<dfs(1, -1)<<endl;
    return 0;
}