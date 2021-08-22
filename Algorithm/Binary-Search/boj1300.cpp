#include <iostream>
#include <algorithm>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    Quick_IO();
    int N, k; cin>>N>>k;

    int l=1, r=k, answer;
    while(l<=r){
        int result = 0;
        int mid = (l+r)/2;
        for (int i = 1; i <= N; ++i) {
            result += min(mid/i, N);
        }
        if(result>=k){
            r = mid-1;
            answer = mid;
        }else{
            l = mid+1;
        }
    }
    cout<<answer<<'\n';
    return 0;
}