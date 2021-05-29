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

int n;
int counts = 0;
vector<int> answer;

int dfs(vector<string>& m, int x, int y) {
    if(m[x][y]=='0') return 0;
    int total = 0;
    if(m[x][y]=='1'){
        m[x][y] = '0';
        total++;
    }

    if(x-1>=0) total += dfs(m, x-1, y);
    if(x+1<n) total += dfs(m, x+1, y);
    if(y-1>=0) total += dfs(m, x, y-1);
    if(y+1<n) total += dfs(m, x, y+1);
    return total;
}

int main(){
    Quick_IO();

    cin>>n;
    vector<string> board;

    for (int i = 0; i < n; ++i) {
        string s;
        cin>>s;
        board.push_back(s);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(board[i][j]=='1'){
                answer.push_back(dfs(board, i, j));
                counts++;
            }
        }
    }
    cout<<counts<<"\n";
    sort(answer.begin(), answer.end());
    for(auto x: answer){
        cout<<x<<"\n";
    }

    return 0;
}


