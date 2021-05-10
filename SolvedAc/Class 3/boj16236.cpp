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

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool visited[21][21];
int board[21][21];
vector<p> fish[7]; // 크기, 좌표(x, y): 해당되는 x와 y중 가장 작은 값을 선택하면 된다.

int getDist(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}

int main(){
    Quick_IO();
    int N;
    cin>>N;
    int x, y;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            int a;
            cin>>a;
            if(a==9){
                x = i;
                y = j;
            }
            board[i][j] = a;
        }
    }
    visited[x][y] = true;
    int eat = 0;
    int size = 2;
    int answer  = 0;
    while(true){
        vector<pair<int, p>> tempCoord;
        for(int i = size-1;i>0;i--){
            for(auto c:fish[i]){
                if(!visited[c.first][c.second]){
                    tempCoord.emplace_back(getDist(c.first, c.second, x, y), p(c.first, c.second));
                }
            }
        }

        if(tempCoord.empty()){
            break;
        }else{
            sort(tempCoord.begin(), tempCoord.end(), [](pair<int, p> a, pair<int, p> b){
                if(a.first == b.first){
                    if(a.second.first==b.second.first){
                        return a.second.second<b.second.second;
                    }else{
                        return a.second.first<b.second.first;
                    }
                }else{
                    return a.first<b.first;
                }
            });
            x = tempCoord[0].second.first;
            y = tempCoord[0].second.second;
            cout<<"Eat fish: "<<"("<<x<<", "<<y<<")";
            visited[x][y] = true;
            answer += tempCoord[0].first;
            eat++;
            if(size<6&&eat==size){
                size++;
                eat = 0;
            }
            cout<<" curr size: "<<size<<" answer: "<<answer<<endl;
        }
    }
    cout<<answer<<"\n";
    return 0;
}