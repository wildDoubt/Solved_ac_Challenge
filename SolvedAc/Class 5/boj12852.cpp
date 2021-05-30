#include <iostream>
#include <algorithm>

using namespace std;

inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int dp[1000001];
int parent[1000001];

int calc(int x){
    if(x==1) return 0;
    if(dp[x]!=0) return dp[x];

    dp[x] = calc(x-1)+1;
    parent[x] = x-1;
    if(x%3==0){
        int temp =calc(x/3)+1;
        if(dp[x]>temp){
            dp[x] = temp;
            parent[x] = x/3;
        }
    }
    if(x%2==0){
        int temp =calc(x/2)+1;
        if(dp[x]>temp){
            dp[x] = temp;
            parent[x] = x/2;
        }
    }
    return dp[x];
}

int main(){
    quick_IO();
    int x;
    cin>>x;
    cout<<calc(x)<<"\n";
    while(x>0){
        cout<<x<<" ";
        x = parent[x];
    }
    cout<<endl;
    return 0;
}