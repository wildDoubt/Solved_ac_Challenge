#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
using p = pair<int, int>;

const int MAX = 1e6+3;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int parent[MAX];
int ranks[MAX];

int find(int a){
    if(parent[a]==a) return a;
    else{
        return parent[a] = find(parent[a]);
    }
}

void _union(int a, int b){
    int x = find(a);
    int y = find(b);

    if(x==y) return;

    if(ranks[x]>ranks[y]) {
        swap(x, y);
    }
    parent[x] = y;
    if(ranks[x]==ranks[y]) {
        ranks[y]++;
    }
}


struct edge {
    p coord;
    int distance;

    edge(p a, int b) {
        coord = a;
        distance = b;
    }
};

struct compare {
    bool operator()(edge a, edge b) {
        return a.distance > b.distance;
    }
};

int N, M;

priority_queue<edge, vector<edge>, compare> pq;

int main() {
    Quick_IO();
    cin >> N>>M;

    for (int i = 1; i <= N; ++i) parent[i] = i;

    for (int i = 0, a, b, c; i < M; ++i) {
        cin>>a>>b>>c;
        pq.push(edge(p(a, b), c));
    }

    int counts = 0;
    int answer = 0;
    int div = 0;

    while(!pq.empty()){
        if(counts==N) break;
        auto [currCoord, currDistance] = pq.top();
        auto [currX, currY] = currCoord;
        pq.pop();
        if(find(currX)==find(currY)){
            continue;
        }else{
            counts++;
            _union(currX, currY);
            answer += currDistance;
            div = max(currDistance, div);
        }
    }
    cout<<answer - div<<'\n';
    return 0;
}