#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>

using namespace std;

typedef struct query{
    int n;
    int s;
    int b;
}query;

const int MAX = 10e+6;
const int INF = 0x66554433;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    Quick_IO();
    int t;
    int n, s, b;
    int answer = 0;
    vector<query> queries;
    cin>>t;
    function<int(int, int, int, int)> check = [](int num, int num1, int s, int b){
        string numString = to_string(num);
        string numString1 = to_string(num1);
        int temps = 0;
        int tempb = 0;
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                if(numString[i]==numString1[j]){
                    if(i==j) temps++;
                    else tempb++;
                }
            }
        }
        if(tempb==b && temps==s) return 1;
        else return 0;
    };
    while(t--){
        cin>>n>>s>>b;
        queries.push_back({n, s, b});
    }

    for(int i = 100;i<1000;i++){
        string a = to_string(i);
        if(a[0]==a[1] || a[1]==a[2] || a[0]==a[2]||a[0]=='0'||a[1]=='0'||a[2]=='0') continue;
        int temp = 0;
        for(auto q:queries){
            temp += check(i, q.n, q.s, q.b);
        }
        if(temp == queries.size()) answer++;
    }
    cout<<answer<<"\n";
    return 0;
}