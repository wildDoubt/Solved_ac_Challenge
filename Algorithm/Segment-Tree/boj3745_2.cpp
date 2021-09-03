// lower bound

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    while (true) {
        int n;
        cin>>n;
        if(cin.eof()) break;
        vector<int> lis;
        for (int i = 0, input; i < n; ++i){
            cin>>input;
            auto pos = lower_bound(lis.begin(), lis.end(), input);
            if(pos==lis.end()) lis.push_back(input);
            else *pos = input;
        }
        cout<<lis.size()<<'\n';
    }

    return 0;
}