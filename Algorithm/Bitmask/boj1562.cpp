#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int MOD = 1e9;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int dp[101][10][1<<10];
int N;

int calc(int curr, int last, int status){
    int &ret = dp[curr][last][status];
    if(ret!=-1) return ret;
    if(curr==N){
        if(status==1023) return 1;

        return 0;
    }
    ret = 0;
    if(last-1>=0){
        ret+=calc(curr+1, last-1, status|(1<<(last-1)))%MOD;
    }
    if(last+1<10){
        ret+=calc(curr+1, last+1, status|(1<<(last+1)))%MOD;
    }

    return ret;
}

int main() {
    Quick_IO();
    cin>>N;
    int answer = 0;
    if(N<10){
        cout<<"0\n";
        return 0;
    }
    memset(dp, -1, sizeof(dp));

    for (int i = 1; i < 10; ++i) {
        answer = (answer%MOD + calc(1, i, 1<<i)%MOD)%MOD;
    }
    cout<<answer<<'\n';
    return 0;
}