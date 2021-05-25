#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>

using namespace std;

typedef struct t{
    int age;
    string name;
    int index;
    t(int a, string b, int c){
        age = a;
        name = b;
        index = c;
    }
}t;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<t> arr;

int main(){
    Quick_IO();
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int a;
        string b;
        cin>>a>>b;
        arr.emplace_back(a, b, i);
    }
    sort(arr.begin(), arr.end(), [](t a, t b){
        if(a.age==b.age) return a.index<b.index;
        return a.age<b.age;
    });
    for(const auto& x:arr){
        cout<<x.age<<" "<<x.name<<"\n";
    }
    return 0;
}