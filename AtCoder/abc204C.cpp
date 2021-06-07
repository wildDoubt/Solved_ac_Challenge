#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>
#include <sstream>

using namespace std;
using p = pair<int, int>;
using ll = long long;
const int MAX = 10e+6;
const int INF = 0x66554433;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<int> adj[2001];
bool visited[2001];

void dfs(int prev, int curr){
    visited[curr] = true;
    for(auto x:adj[curr]){
        if(!visited[x]){
            dfs(curr, x);
        }
    }
}

int main(){
    Quick_IO();
    int N, M;
    cin>>N>>M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    ll answer = 0;
    for (int i = 1; i <= N; ++i) {
        dfs(-1, i);
        for (int j = 1; j <=N; ++j) {
            if(visited[j]) answer++;
        }
        fill(visited+1, visited+N+1, false);
    }
    cout<<answer<<"\n";
    return 0;
}