#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using p = pair<int, int>;

const int INF = 0x66554433;

inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


int main(){
    quick_IO();
    int t;
    cin>>t;
    while(t--){
        int n;
        ull answer = 0;
        vector<int> temp;
        string a;
        cin>>n>>a;
        for (int i = 0; i < n; ++i) {
            if(a[i]=='*') temp.push_back(i);
        }
        if(temp.empty()){
            cout<<answer<<"\n";
            continue;
        }
        int mid = temp[temp.size()/2];
        for(int i = 0;i<temp.size();i++){
            answer += abs(temp[i] - mid+(int)temp.size()/2 - i);
        }
        cout<<answer<<"\n";
    }
    return 0;
}