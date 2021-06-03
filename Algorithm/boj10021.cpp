// 33분

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;
using p = pair<int, int>;
using ll = long long;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int parent[2001];
int ranks[2001];

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

int calc(int x1, int y1, int x2, int y2){
    int x_2 = abs(x2-x1);
    int y_2 = abs(y2-y1);
    return x_2*x_2 + y_2*y_2;
}

int main(){
    Quick_IO();
    for (int i = 0; i < 2001; ++i) {
        parent[i] = i;
    }

    int N, C;
    cin>>N>>C;
    vector<p> pos(N);
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin>>x>>y;
        pos[i] = p(x, y);
    }
    vector<pair<int, p>> dist;
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            int d = calc(pos[i].first, pos[i].second, pos[j].first, pos[j].second);
            if(d>=C){
                dist.emplace_back(d, p(i, j));
            }
        }
    }
    sort(dist.begin(), dist.end());
    ll answer = 0;
    int index = 0;
    int counts = 0;
    while(counts<N-1){
        if(index>(int)dist.size()-1){
            answer = -1;
            break;
        }
        if(find(dist[index].second.first)!=find(dist[index].second.second)){
            answer+=dist[index].first;
            _union(dist[index].second.first,dist[index].second.second );
            counts++;
        }
        index++;
    }
    cout<<answer<<"\n";
    return 0;
}