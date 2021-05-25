#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <set>
#include <queue>
#include <stack>

using namespace std;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    Quick_IO();
    int K;
    cin>>K;
    stack<int> st;
    while(K--){
        int a;
        cin>>a;
        if(a==0){
            st.pop();
        }else{
            st.push(a);
        }
    }
    int total = 0;
    while(!st.empty()){
        total += st.top();
        st.pop();
    }
    cout<<total<<"\n";
    return 0;
}