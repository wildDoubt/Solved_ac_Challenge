#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t, odd, even;
    string num;
    cin >> t;
    while (t--) {
        cin>>num;
        string oddS, evenS;
        for (int i = 0; i <(int)num.size() ; ++i) {
            if(i%2){
                oddS += string(1, num[i]);
            }else{
                evenS += string(1, num[i]);
            }
        }
        if(oddS.empty()) oddS = "0";
        if(evenS.empty()) evenS = "0";

        odd = stoi(oddS), even = stoi(evenS);
        cout<<(odd+1)*(even+1)-2<<'\n';
    }

    return 0;
}