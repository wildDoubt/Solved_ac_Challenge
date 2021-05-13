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
const int MAX = 1000000;
const int INF = 0x66554433;

//inline void Quick_IO(){
//    ios_base :: sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//}
inline int readInt(){
    int a;
    scanf("%d", &a);
    return a;
}
bool isPrime[MAX+1];
int main(){
//    Quick_IO();
    int M, N;
    M = readInt();
    N = readInt();
    fill(isPrime+2, isPrime+N+1, true);
    for(int i = 4;i<=N;i+=2){
        isPrime[i] = false;
    }
    for(int i = 3;i<=N;i+=2){
        if(!isPrime[i]) continue;
        if(1LL*i*i>N) continue;

        for (int j = i * i; j <= N; j += i * 2) {
            isPrime[j] = false;
        }
    }
    for(int k = M;k<=N;k++){
        if(isPrime[k]) printf("%d\n", k);
    }

    return 0;
}