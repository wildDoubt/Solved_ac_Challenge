#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
using p = pair<int, int>;
const int MAX = 1e5;

int N, K;
int moves[] = {-1, 0, 1};
bool visited[MAX+1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> N >> K;
    queue<p> q; // index, counts

    q.push(p(N, 0));

    while (!q.empty()) {
        auto[currIndex, currCounts] = q.front();
        q.pop();
        if (currIndex == K) {
            cout << currCounts << '\n';
            return 0;
        }
        if(currIndex>MAX || currIndex<0) continue;
        if (!visited[currIndex]) {
            for (int move:moves) {
                if (!move) q.push(p(currIndex * 2, currCounts));
                else q.push(p(currIndex + move, currCounts + 1));
            }
        }
        visited[currIndex] = true;
    }
    return 0;
}