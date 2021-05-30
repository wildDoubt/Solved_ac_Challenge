#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int dp[1005][1005];
string a, b;

void lcs(int x, int y){
    if(dp[x][y]==0) return;
    if(a[x-1]==b[y-1]){
        lcs(x-1, y-1);
        cout<<a[x-1];
    }else{
        if(dp[x-1][y]>dp[x][y-1]){
            lcs(x-1, y);
        }else{
            lcs(x, y-1);
        }
    }
}

int main() {
    Quick_IO();

    cin >> a >> b;
    int a_size = (int)a.size();
    int b_size = (int)b.size();

    for (int i = 0; i < a_size; ++i) {
        for (int j = 0; j < b_size; ++j) {
            if(a[i]==b[j]){
                dp[i+1][j+1] = dp[i][j]+1;
            }else{
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    for (int i = 0; i <= a_size; ++i) {
        for (int j = 0; j <= b_size; ++j) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[a_size][b_size]<<"\n";
    lcs(a_size, b_size);
    return 0;
}