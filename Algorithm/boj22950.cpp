#include <iostream>

using namespace std;

int main() {
    int N, K; cin>>N;
    string M; cin>>M;
    cin>>K;

    int size = (int)M.size();
    bool isDivided = true;
    for (int i = 0; i < K && size-1-i>=0; ++i) {
        if(M[size-1-i]=='1'){
            isDivided = false;
            break;
        }
    }
    if(isDivided) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}