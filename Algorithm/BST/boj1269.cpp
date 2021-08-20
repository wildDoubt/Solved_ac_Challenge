#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    Quick_IO();
    int A, B; cin>>A>>B;
    set<int> S;
    for (int i = 0, input; i < A; ++i) {
        cin >> input;
        S.insert(input);
    }
    for (int i = 0, input; i < B; ++i) {
        cin>>input;
        if(S.count(input)) S.erase(input);
        else S.insert(input);
    }
    cout<<S.size()<<'\n';
    return 0;
}