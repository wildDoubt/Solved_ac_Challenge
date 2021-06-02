#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>
#include <queue>
#include <sstream>

using namespace std;
using p = pair<int, int>;
using ll = long long;
const int MAX = 10e+6;
const int INF = 0x66554433;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

struct compare{
    bool operator()(p a, p b){
        if(a.second==b.second){
            return a.first>b.first;
        }
        return a.second<b.second;
    }
};

int main(){
    Quick_IO();
    int N, K;
    cin>>N>>K;

    priority_queue<p, vector<p>, compare> pq_jewel;
    multiset<int> bag;
    for (int i = 0; i < N; ++i) {
        int M, V;
        cin>>M>>V;
        pq_jewel.push(p(M, V));
    }
    ll answer = 0;
    for (int i = 0; i < K; ++i) {
        int C;
        cin>>C;
        bag.insert(C);
    }
    while(!pq_jewel.empty()){
        int w = pq_jewel.top().first;
        int v = pq_jewel.top().second;

        auto pos = bag.lower_bound(w);
        if(pos!=bag.end()){
            bag.erase(pos);
            answer+=v;
        }
        pq_jewel.pop();
    }
    cout<<answer<<"\n";
    return 0;
}