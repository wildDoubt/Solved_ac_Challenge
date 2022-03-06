#include <iostream>
#include <algorithm>

using namespace std;

void calc(vector<int> &lis, int input) {
    auto iter = lower_bound(lis.begin(), lis.end(), input);
    if(iter == lis.end()){
        lis.push_back(input);
    }else{
        *iter = input;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N;
    cin>>N;
    vector<int> lis;
    for (int i = 0, input; i < N; ++i) {
        cin >> input;
        calc(lis, input);
    }

    cout << N - lis.size() << '\n';

    return 0;
}


