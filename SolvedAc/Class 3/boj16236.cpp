#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>
#include <map>

using namespace std;
using p = pair<int, int>;
using ll = long long;
const int MAX = 10e+6;
const int INF = 0x66554433;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
typedef struct fish{
    int dist;
    int x;
    int y;
} fish;
int board[21][21];
bool visited[21][21];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
struct compare{
    bool operator()(fish a, fish b){
        if(a.dist==b.dist){
            if(a.x==b.x){
                return a.y>b.y;
            }
            return a.x>b.x;
        }
        return a.dist>b.dist;
    }
};

int main() {
    Quick_IO();
    int N;
    cin >> N;
    int x, y;
    queue<fish> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                q.push({0, i, j});
                board[i][j] = 0;
                visited[i][j] = true;
            }
        }
    }
    int eat = 0;
    int size = 2;
    int answer = 0;
    while (true) {
        priority_queue<fish, vector<fish>, compare> pq;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(int i = 0;i<4;i++){
                int nx = curr.x + dx[i];
                int ny = curr.y + dy[i];
                if(nx<0 || nx>=N||ny<0||ny>=N){
                    continue;
                }
                if(board[nx][ny] > size || visited[nx][ny]){
                    continue;
                }
                q.push({curr.dist+1, nx, ny});
                visited[nx][ny] = true;
                if(board[nx][ny]<size && board[nx][ny]!=0){
                    pq.push({curr.dist+1, nx, ny});
                }
            }
        }
        for(int i = 0;i<N;i++) fill(visited[i], visited[i] + N, false);

        if(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            eat++;
            board[cur.x][cur.y] = 0;
            visited[cur.x][cur.y] = true;
            answer = cur.dist;
            q.push({cur.dist, cur.x, cur.y});
            if(size==eat){
                eat = 0;
                size++;
            }
        }else{
            break;
        }

    }
    cout << answer << "\n";
    return 0;
}