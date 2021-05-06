#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>

using namespace std;

const int MAX = 10e+6;
const int INF = 0x66554433;
const string B = "BWBWBWBW";
const string W = "WBWBWBWB";
vector<string> startB;
vector<string> startW;
inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int check(const vector<string>& board, int x, int y){
    int valueB = 0, valueW = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if(board[x+i][y+j]!=startB[i][j]){
                valueB++;
            }
            if(board[x+i][y+j]!=startW[i][j]){
                valueW++;
            }
        }
    }
    return min(valueB, valueW);
}

int main(){
    Quick_IO();
    int n, m;
    int answer = INF;
    cin>>n>>m;
    vector<string> maps;
    for (int i = 0; i < 8; ++i) {
        if(i%2==0){
            startB.push_back(B);
            startW.push_back(W);
        }else{
            startB.push_back(W);
            startW.push_back(B);
        }
    }
    for (int i = 0; i < n; ++i) {
        string temp;
        cin>>temp;
        maps.push_back(temp);
    }
    for (int i = 0; i < n-7; ++i) {
        for (int j = 0; j < m- 7; ++j) {
            answer = min(answer, check(maps, i, j));
        }
    }
    cout<<answer<<"\n";
    return 0;
}