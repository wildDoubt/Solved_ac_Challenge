#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <set>
#include <queue>

using namespace std;
using p = pair<int, int>;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

struct compare{
    bool operator()(p a, p b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first>b.first;
    }
};

int main() {
    Quick_IO();
    int N;
    cin>>N;
    priority_queue<p, vector<p>, compare> cows;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin>>a>>b;
        cows.push(p(a, b));
    }
    int total_time = 0;
    while(!cows.empty()){
        auto [arrive_time, test_time] = cows.top();
//        int arrive_time = cows.top().first;
//        int test_time = cows.top().second;
        if(total_time<arrive_time){
            total_time = arrive_time;
        }
        total_time += test_time;
        cows.pop();
    }
    cout<<total_time<<'\n';

    return 0;
}