#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
using p = pair<int, int>;
const int MAX = 1e5 + 5;

vector<p> adj[MAX];
int s, e;
bool visited[MAX];

int bfs(int weight) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto[next, nextWeight]: adj[curr]){
            if(nextWeight < weight) continue;
            if(next == e) return true;
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 0, A, B, C; i < M; ++i) {
        cin >> A >> B >> C;
        adj[A].emplace_back(B, C);
        adj[B].emplace_back(A, C);
    }

    cin >> s >> e;
    int l = 0, r = 1e9, answer = INT32_MIN;
    while(l <= r){
        fill(visited, visited + MAX, false);
        int mid = (l + r) / 2;
        if(bfs(mid)){
            answer = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << answer << '\n';
    return 0;
}

