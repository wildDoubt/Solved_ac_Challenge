#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> parents[32001];
bool visited[32001];

void solve(int curr){
    for(auto parent:parents[curr]){
        if(!visited[parent]){
            solve(parent);
            visited[parent] = true;
        }
    }
    if(!visited[curr]){
        visited[curr] = true;
        cout<<curr<<" ";
    }
}

int main() {
    cin>>N>>M;

    for (int i = 0, A, B; i < M; ++i) {
        cin>>A>>B;
        parents[B].push_back(A);
    }

    for (int i = 1; i <= N; ++i) {
        solve(i);
    }

    return 0;
}