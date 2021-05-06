#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>

using namespace std;

const int MAX = 10e+6;
const int INF = 0x66554433;

vector<string> maps;
int n;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int check(){
    int result = 0;
    for (int i = 0; i < n; ++i) {
        int temp = 1;
        for (int j = 1; j < n; ++j) {
            if(maps[i][j] == maps[i][j-1]) temp++;
            else{
                result = max(result, temp);
                temp = 1;
            }
        }
        result = max(result, temp);
    }
    for (int i = 0; i < n; ++i) {
        int temp = 1;
        for (int j = 1; j < n; ++j) {
            if(maps[j][i] == maps[j-1][i]) temp++;
            else{
                result = max(result, temp);
                temp = 1;
            }
        }
        result = max(result, temp);
    }
    return result;
}

int main(){
    Quick_IO();

    int maxValue = 0;
    string a;
    cin>>n;


    for (int i = 0; i < n; ++i) {
        cin>>a;
        maps.push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-1; ++j) {
            swap(maps[i][j], maps[i][j+1]);
            maxValue = max(maxValue, check());
            swap(maps[i][j], maps[i][j+1]);
            swap(maps[j][i], maps[j+1][i]);
            maxValue = max(maxValue, check());
            swap(maps[j][i], maps[j+1][i]);
        }
    }
    cout<<maxValue<<endl;
    return 0;
}

