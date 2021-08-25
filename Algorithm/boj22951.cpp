#include <iostream>
#include <algorithm>

using namespace std;
using p = pair<int, int>;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<p> arr;

int main() {
    Quick_IO();
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        for (int j = 0, a; j < K; ++j) {
            cin >> a;
            arr.emplace_back(i, a);
        }
    }
    int currIndex = 0;
    while((int)arr.size()>1){
        int next = arr[currIndex].second;
        next--;
        arr.erase(arr.begin()+currIndex);
        currIndex = (currIndex+next)%(int)arr.size();
    }
    cout<<arr.front().first+1<<" "<<arr.front().second<<'\n';
    return 0;
}