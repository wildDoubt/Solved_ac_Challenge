#include <iostream>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    Quick_IO();
    int t, c, d;
    cin >> t;
    while (t--) {
        cin>>c>>d;
        if((c+d)%2==1){
            cout<<"-1\n";
        }else{
            if(c==d){
                if(c==0){
                    cout<<"0\n";
                }else{
                    cout<<"1\n";
                }
            }else{
                cout<<"2\n";
            }
        }
    }

    return 0;
}