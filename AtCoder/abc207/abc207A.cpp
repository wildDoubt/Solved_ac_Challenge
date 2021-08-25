#include <iostream>
#include <algorithm>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    Quick_IO();
    int A, B, C;
    cin>>A>>B>>C;
    cout<<A + B + C - min({A, B, C});

    return 0;
}