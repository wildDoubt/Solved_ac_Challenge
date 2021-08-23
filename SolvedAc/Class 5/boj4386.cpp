#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
using p = pair<int, int>;
using pd = pair<double, double>;
const int MAX = 101;
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
    double distance;

    edge(p a, double b) {
        coord = a;
        distance = b;
    }
};

struct compare {
    bool operator()(edge a, edge b) {
        return a.distance > b.distance;
    }
};

int N;
pd arr[101];
priority_queue<edge, vector<edge>, compare> pq;
bool visited[101];

double dist(double x1, double y1, double x2, double y2) {
    double d1, d2;
    d1 = pow(x1-x2, 2);
    d2 = pow(y1-y2, 2);
    return sqrt(d1 + d2);
}

int main() {
    Quick_IO();
    cin >> N;
    cout.precision(6);
    for (int i = 1; i <= N; ++i) parent[i] = i;
    double a, b;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        arr[i] = pd(a, b);
    }
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            pq.push(edge(p(i, j), dist(arr[i].first, arr[i].second, arr[j].first, arr[j].second)));
        }
    }

    int counts = 0;
    double answer = 0.0;

    while(!pq.empty()){
        if(counts==N) break;
        auto [currCoord, currDistance] = pq.top();
        auto [currX, currY] = currCoord;
//        cout<<currX<<" "<<currY<<" "<<currDistance<<'\n';
        pq.pop();
        if(find(currX)==find(currY)){
            continue;
        }else{
            counts++;
            _union(currX, currY);
            answer += currDistance;
        }
    }
    cout<<fixed<<answer<<'\n';
    return 0;
}