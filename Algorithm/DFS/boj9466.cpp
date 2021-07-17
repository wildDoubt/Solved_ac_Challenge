#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e5+5;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int arr[MAX];
bool visited[MAX];
bool finished[MAX];
int cycle_component = 0;

void dfs(int curr){
    visited[curr] = true;
    int next = arr[curr];
    if(visited[next]){
        if(!finished[next]){
            for (int i = next; i != curr; i=arr[i]) {
                cycle_component++;
            }
            cycle_component++;
        }
    }else{
        dfs(next);
    }

    finished[curr] = true;
}

int main() {
    Quick_IO();
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        fill(visited, visited+N+1, false);
        fill(finished, finished+N+1, false);
        cycle_component = 0;
        for (int i = 1; i <= N; ++i) {
            int a;
            cin>>a;
            arr[i] = a;
        }
        for (int i = 1; i <= N; ++i) {
            if(!visited[i])
                dfs(i);
        }
        cout<<N-cycle_component<<'\n';
    }

    return 0;
}