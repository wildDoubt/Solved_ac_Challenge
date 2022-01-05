#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 51;
int parent[MAX];

int find(int v){
    if(v==parent[v]) return v;
    return parent[v] = find(parent[v]);
}

void merge(int a, int b){
    int x = find(a);
    int y = find(b);
    if(x>y) swap(x, y);
    parent[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    for (int i = 0; i < MAX; ++i) {
        parent[i] = i;
    }
    int N, M, t;
    cin>>N>>M;
    cin>>t;
    vector<int> party[M];

    for (int i = 0, input; i < t; ++i) {
        cin>>input;
        merge(0, input);
    }

    for (int i = 0; i < M; ++i) {
        int p;
        cin>>p;
        for (int j = 0, input; j < p; ++j) {
            cin>>input;
            party[i].push_back(input);
        }
    }
    for (int i = 0; i < M; ++i) {
        int size = (int)party[i].size();
        for (int j = 0; j < size-1; ++j) {
            for (int k = j+1; k < size; ++k) {
                merge(party[i][j], party[i][k]);
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < M; ++i) {
        int size = (int)party[i].size();
        int flag = true;
        for (int j = 0; j < size; ++j) {
            if(find(party[i][j])==0){
                flag = false;
                break;
            }
        }
        if(flag) answer++;
    }
    cout<<answer<<'\n';
    return 0;
}