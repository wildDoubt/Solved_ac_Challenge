#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

inline void quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    quick_IO();
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> arr(N);
        for (auto& x:arr) {
            cin>>x;
        }
        sort(arr.begin(), arr.end());
        int answer = 1;
        int d = INT32_MAX;
        for (int i = 1; i < N; ++i) {
            d = min(d, arr[i] - arr[i-1]);
            if(arr[i]>d) break;
            answer++;
        }
        cout<<answer<<"\n";
    }
    return 0;
}