#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using p = pair<int, int>;

const int INF = 0x66554433;

inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int arr[2200][2200];
int answer[3];
bool check(int x1, int y1, int x2, int y2){
    int temp = arr[x1][y1];
    for(int i = x1;i<x2;i++){
        for(int j = y1;j<y2;j++){
            if(temp!=arr[i][j]) return false;
        }
    }
    return true;
}

void calc(int x1, int y1, int x2, int y2){
    if(check(x1, y1, x2, y2)){
        answer[arr[x1][y1]+1]++;
        return;
    }
    int d = (x2-x1)/3;
    for(int i = 0;i<3;i++){
        for (int j = 0; j < 3; ++j) {
            int new_x1 = x1+i*d;
            int new_y1 = y1+j*d;
            int new_x2 = x1+(i+1)*d;
            int new_y2 = y1+(j+1)*d;
            calc(new_x1, new_y1, new_x2, new_y2);
        }
    }
}

int main(){
    quick_IO();
    int n;
    cin>>n;
    for (int i = 0; i <n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>arr[i][j];
        }
    }
    calc(0, 0, n, n);
    for(int ans:answer){
        cout<<ans<<"\n";
    }
    return 0;
}