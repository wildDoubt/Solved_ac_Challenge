#include <iostream>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    Quick_IO();
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin>>l>>r;

        if(r<l*2){
            cout<<r%l<<'\n';
        }else{
            cout<<(r+1)/2 -1 <<'\n';
        }
    }

    return 0;
}