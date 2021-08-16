#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int N, K;

bool check(int num) {
    for (int i = 0; i < N - 1; ++i) {
        int curr = ((num & (7 << (i * 3))) >> (i * 3));
        int next = ((num & (7 << ((i + 1) * 3))) >> ((i + 1) * 3));
        if (curr > next) return false;
    }
    return true;
}

void printNum(int num) {
    for (int i = 0; i < N; ++i) {
        int curr = ((num & (7 << (i * 3))) >> (i * 3));
        cout << curr + 1 << " ";
    }
    cout << endl;
}

int reverseNum(int num, int start, int k) {
    int temp = num;
    for (int i = start + k - 1; i >= start; --i) {
        temp &= (-(7 << ((i) * 3)) - 1);
//        cout << i <<" "<<(start + k - 1 - i)<< endl;
//        printNum(temp);
//        temp |= ((((num & (7 << (i * 3)))) >> (i * 3)) << ((start + k - 1 - i) * 3));
    }
    for (int i = start + k - 1; i >= start; --i) {
        temp |= ((((num & (7 << (i * 3)))) >> (i * 3)) << ((2*start + k - 1 - i) * 3));
    }
    return temp;
}

int main() {
    Quick_IO();
    cin >> N >> K;
    int a, value = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a;
        value |= (--a << (i * 3));
    }
    // 2^24으로 현재 상태 표현
    queue<int> q;
    q.push(value);
    int level = 0;
    set<int> visited;
    while (!q.empty()) {
        int size = (int) q.size();
        for (int i = 0; i < size; ++i) {
            int curr = q.front();
//            printNum(curr);
            if (check(curr)) {
                cout << level << '\n';
                return 0;
            }
            q.pop();
            if(!visited.count(curr)){
                visited.insert(curr);

                for (int j = 0; j < N - K + 1; ++j) {
                    q.push(reverseNum(curr, j, K));
                }
            }

        }
        level++;
    }
//    printNum(value);
//    printNum(reverseNum(value, 2, 3));
    cout << -1 << '\n';

    return 0;
}