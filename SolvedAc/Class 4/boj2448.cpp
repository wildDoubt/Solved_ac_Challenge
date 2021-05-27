#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>

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

int board[6144][6144];

void draw(int x1, int y1, int x2, int y2){
    if(x1+2==x2&&y1+5==y2){
        board[x1][y1+2] = 1;
        board[x1+1][y1+1] = 1;
        board[x1+1][y1+3] = 1;
        for (int i = 0; i < 5; ++i) {
            board[x1+2][y1+i] = 1;
        }
        return;
    }
    // 3부분으로 분할
    int dx = x2 - x1;
    int dy = y2 - y1;
    draw(x1, y1+dy/4+1, x1+dx/2, y2-dy/4-1); // 위쪽 부분
    draw(x1+dx/2+1, y1, x2, y1+dy/2);
    draw(x1+dx/2+1, y1+dy/2+1, x2, y2);
}

int main(){
    Quick_IO();
    int n;
    cin>>n;
    n*=2;
    draw(0, 0, n/2-1, n-1);
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < n; ++j) {
            if(board[i][j]==1)
                cout<<'*';
            else
                cout<<' ';
        }
        cout<<"\n";
    }
    return 0;
}