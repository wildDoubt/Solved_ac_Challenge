#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int N;

void dfs(int index, const string& curr) {
    if (index == N) {
        cout<<curr<<'\n';
        exit(0);
    }

    for (int i = 0; i < 3; ++i) {
        bool flag = false;
        char ch = '1' + i;
        for (int j = 1; index-2*j+1>=0; ++j) {
            if(curr.substr(index-j+1, j-1) + ch ==curr.substr(index-2*j+1, j)){
                flag = true;
                break;
            }
        }
        if(!flag) dfs(index+1, curr+ch);
    }
}

int main() {
    Quick_IO();
    cin >> N;
    dfs(0, "");
    return 0;
}