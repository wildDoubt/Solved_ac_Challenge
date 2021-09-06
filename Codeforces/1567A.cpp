#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string a, answer;
        cin>>n>>a;
        for (int i = 0; i < (int)a.size(); ++i) {
            if(a[i]=='U'){
                answer+='D';
            }else if(a[i]=='D'){
                answer+='U';
            }else{
                answer+=a[i];
            }
        }
        cout<<answer<<'\n';
    }

    return 0;
}