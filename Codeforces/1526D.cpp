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
const int MAX = 1e6+5;

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
        string a, b;
        cin>>a;
        if(a.size()%2==0){
            string temp = a.substr(a.size()/2, a.size()/2);
            string temp1 = a.substr(0, a.size()/2);
            reverse(temp1.begin(), temp1.end());
            b = temp+temp1;
        }else{
            char midIndex = a.size()/2;
            if(a[midIndex-1]!=a[midIndex]){
                swap(a[midIndex-1], a[midIndex]);
            }
            string temp = a.substr(a.size()/2+1, a.size()/2);
            string temp1 = a.substr(0, a.size()/2+1);
            reverse(temp1.begin(), temp1.end());
            b = temp+temp1;
        }

        cout<<b<<"\n";
    }
    return 0;
}