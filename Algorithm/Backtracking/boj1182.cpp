#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int arr[20];
bool visited[20];
int N, S;
int answer;

void dfs(int curr, int total){
    for (int i = curr+1; i < N; ++i) {
        if(!visited[i]){
            visited[i] = true;
            dfs(i, total+arr[i]);
            if(total+arr[i]==S) answer++;
            visited[i] = false;
        }

    }
}

int main() {
    Quick_IO();
    cin>>N>>S;
    for (int i = 0; i < N; ++i) {
        cin>>arr[i];
    }
    dfs(-1, 0);
    cout<<answer<<'\n';
    return 0;
}