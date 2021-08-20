#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e5+5;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int pArr[MAX][3];

int main() {
    Quick_IO();

    int N, Q;
    cin>>N>>Q;

    for (int i = 1, input; i <= N; ++i) {
        cin>>input;
        input--;
        for (int j = 0; j < 3; ++j) {
            pArr[i][j] += pArr[i-1][j];
            if(input==j) pArr[i][input]++;
        }
    }

    for (int i = 0, a, b; i < Q; ++i) {
        cin>>a>>b;
        for (int j = 0; j < 3; ++j) cout<<pArr[b][j] - pArr[a-1][j]<<" ";
        cout<<'\n';
    }
    return 0;
}