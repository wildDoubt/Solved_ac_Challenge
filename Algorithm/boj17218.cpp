#include <iostream>
#include <algorithm>

using namespace std;

string a, b;
int dp[41][41];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> a >> b;

    a = " " + a;
    b = " " + b;

    for (int i = 1; i < a.size(); ++i) {
        for (int j = 1; j < b.size(); ++j) {
            if(a[i]==b[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int x = a.size()-1, y = b.size()-1;
    string answer;
    while(x>0&&y>0){
        if(dp[x-1][y] == dp[x][y-1] && dp[x-1][y-1] < dp[x][y]){
            answer+=a[x];
            x--;
            y--;
        }else if(dp[x-1][y]>dp[x][y-1]){
            x--;
        }else{
            y--;
        }
    }
    reverse(answer.begin(), answer.end());
    cout<<answer<<'\n';
    return 0;
}