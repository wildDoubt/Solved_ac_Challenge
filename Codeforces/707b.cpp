#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 0x66554433;

inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
typedef struct edge{
    int u;
    int v;
    int l;
    edge(int a, int b, int c){
        u = a;
        v = b;
        l = c;
    }
} edge;
vector<edge> arr;
bool check[100001];

int main(){
    quick_IO();
    int n, m, k;
    int u, v, l;
    cin>>n>>m>>k;
    for (int i = 0; i < m; ++i) {
        cin>>u>>v>>l;
        arr.emplace_back(u, v, l);
    }
    int answer = INF;
    int temp;
    for (int i = 0; i < k; ++i) {
        cin>>temp;
        check[temp] = true;
    }
    for(auto edge:arr){
        if((check[edge.u] && !check[edge.v])||(check[edge.v]&&!check[edge.u])){
            answer = min(answer, edge.l);
        }
    }
    if(answer!=INF) cout<<answer;
    else cout<<-1;
    cout<<"\n";
    return 0;
}