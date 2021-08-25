#include <iostream>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    Quick_IO();
    int N;
    cin>>N;

    if(N%2){
        for (int i = 1; i <= N/2; ++i) {
            cout<<i<<" "<<N-i<<" ";
        }
    }else{
        for (int i = 1; i < N/2; ++i) {
            cout<<i<<" "<<N-i<<" ";
        }
        cout<<N/2<<" ";
    }
    cout<<N<<'\n';
    return 0;
}