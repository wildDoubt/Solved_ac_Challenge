#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
vector<int> answer;
int main(){
    Quick_IO();
    int N, M;
    cin>>N>>M;
    vector<int> cards(N);
    for (auto& card:cards) cin>>card;
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            for (int k = j+1; k < N; ++k) {
                int temp = cards[i]+cards[j]+cards[k];
                if(temp<=M) answer.push_back(temp);
            }
        }
    }
    sort(answer.begin(), answer.end(), [](int a, int b){
        return a>b;
    });
    cout<<answer.front()<<"\n";
    return 0;
}