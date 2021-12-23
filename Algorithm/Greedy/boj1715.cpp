#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N, answer = 0;
    priority_queue<int, vector<int>, greater<>> pq;

    cin>>N;

    for (int i = 0, input; i < N; ++i) {
        cin>>input;
        pq.push(input);
    }

    if(N==1){
        cout<<0<<'\n';
        return 0;
    }

    while(!pq.empty()){
        if(pq.size()==1) break;

        int first, second;

        first = pq.top();
        pq.pop();
        second = pq.top();
        pq.pop();
        pq.push(first + second);
        answer += first + second;
    }
    cout<<answer<<'\n';
    return 0;
}