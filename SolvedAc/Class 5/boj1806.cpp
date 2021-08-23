#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e6 + 5;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int arr[MAX];
vector<int> answers;

int main() {
    Quick_IO();
    int N, S;
    cin >> N >> S;
    for (int i = 0; i < N; ++i) cin >> arr[i];

    int p1 = 0, p2 = 0, sum = arr[0];

    while (p1 <= p2 && p2 < N) {
        if (sum < S) {
            sum += arr[++p2];
        } else if (sum > S) {
            answers.push_back(p2 - p1 + 1);
            sum -= arr[p1++];
        } else {
            answers.push_back(p2 - p1 + 1);
            sum += arr[++p2];
        }
    }

    if (answers.empty()) {
        cout << "0\n";
    } else {
        sort(answers.begin(), answers.end());
        cout << answers.front() << '\n';
    }


    return 0;
}