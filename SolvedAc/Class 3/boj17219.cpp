#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N, M;
    string address, password;
    cin >> N >> M;

    unordered_map<string, string> map;

    for (int i = 0; i < N; ++i){
        cin>>address>>password;
        map[address] = password;
    }

    for (int i = 0; i < M; ++i) {
        cin>>address;
        cout<<map[address]<<'\n';
    }
    return 0;
}