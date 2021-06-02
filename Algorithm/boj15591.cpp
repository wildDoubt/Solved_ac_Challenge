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

vector<p> adj[5005];


int main(){
    Quick_IO();
    int N, Q;
    cin>>N>>Q;
    for (int i = 0; i < N - 1; ++i) {
        int p, q, r;
        cin>>p>>q>>r;
        adj[p].emplace_back(q, r);
        adj[q].emplace_back(p, r);
    }

    for (int i = 0; i < Q; ++i) {
        int k, v;
        cin>>k>>v;
        queue<p> q;
        q.push(p(v, INF));
        bool visited[N+1];
        fill(visited, visited+N+1, false);
        int counts = 0;
        while(!q.empty()){
            p curr = q.front();
            q.pop();
            visited[curr.first] = true;
            for(auto x:adj[curr.first]){
                if(!visited[x.first]&&x.second>=k){
                    q.push(p(x.first, min(curr.second,x.second)));
                    counts++;
                }
            }
        }
        cout<<counts<<"\n";
    }

    return 0;
}