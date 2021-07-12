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

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int board[21][21];
int N;

int calc(const vector<bool>& team){
    // 1: start
    // 0: link

    int start_score = 0;
    int link_score = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            if(team[i] && team[j]){
                // start
                start_score+=(board[i][j]+board[j][i]);
            }
            if(!team[i]&&!team[j]){
                // link
                link_score+=(board[i][j]+board[j][i]);
            }
        }
    }
    return abs(start_score-link_score);
}

int main() {
    Quick_IO();
    cin>>N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>board[i][j];
        }
    }
    int choose = N/2;
    vector<bool> comb(N, false);
    for (int i = 0; i < choose; ++i) {
        comb[i] = true;
    }
    int answer = INF;
    do{
        answer = min(answer, calc(comb));
    }while(prev_permutation(comb.begin(), comb.end()));
    cout<<answer<<'\n';
    return 0;
}