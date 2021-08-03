#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 17;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int arr[MAX];
int N;
int answer;

bool calc(int x) {
    for (int i = 0; i < x; ++i) {
        if(arr[x]==arr[i]||abs(arr[x] - arr[i])==abs(x-i)){
            return false;
        }
    }
    return true;
}

void dfs(int x) {
    if(x==N){
        answer++;
        return;
    }
    for (int i = 0; i < N; ++i) {
        arr[x] = i;
        if(calc(x)) dfs(x+1);
    }
}

int main() {
    Quick_IO();
    cin >> N;
    dfs(0);
    cout << answer << '\n';
    return 0;
}