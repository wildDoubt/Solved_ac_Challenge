#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>

using namespace std;

const int MAX = 10e+6;
const int INF = 0x66554433;



void check(char i);

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void check(char c) {

}

int main(){
    Quick_IO();
    int n;
    int maxValue = 0;
    string a;
    cin>>n;
    vector<string> maps;

    for (int i = 0; i < n; ++i) {
        cin>>a;
        maps.push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-1; ++j) {
            // 가로 swap
            char p = maps[i][j], q = maps[i][j+1];
            int temp, temp1 = 0, temp2 = 0;
            for(int k = i-1;k>=0;k++){
                if(maps[k][j] == p) temp1++;
                else break;
            }
            for(int k = i+1;k<n;k++){
                if(maps[k][j] == p) temp1++;
                else break;
            }
            for(int k = i-1;k>=0;k++){
                if(maps[k][j+1] == q) temp2++;
                else break;
            }
            for(int k = i+1;k<n;k++){
                if(maps[k][j+1] == q) temp2++;
                else break;
            }
            temp = max(temp1, temp2);
            maxValue = max(temp, maxValue);
        }
    }
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n-1; ++i) {
            // 세로 swap
            char p = maps[i][j], q = maps[i][j+1];
            int temp, temp1 = 0, temp2 = 0;
            for(int k = i-1;k>=0;k++){
                if(maps[k][j] == p) temp1++;
                else break;
            }
            for(int k = i+1;k<n;k++){
                if(maps[k][j] == p) temp1++;
                else break;
            }
            for(int k = i-1;k>=0;k++){
                if(maps[k][j+1] == q) temp2++;
                else break;
            }
            for(int k = i+1;k<n;k++){
                if(maps[k][j+1] == q) temp2++;
                else break;
            }
            temp = max(temp1, temp2);
            maxValue = max(temp, maxValue);

        }
    }

    return 0;
}

