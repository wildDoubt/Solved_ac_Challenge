#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
using p = pair<int, int>;
const int MAX = 1e6;

int arr[MAX];
int path[MAX];
vector<p> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        auto it = lower_bound(v.begin(), v.end(), p(arr[i], 0), [](p a, p b) {
            return a.first < b.first;
        });
        if (it == v.end()) {
            int prevIndex;
            if (it != v.begin()) {
                prevIndex = v.back().second;
            } else {
                prevIndex = -1;
            }
            v.emplace_back(arr[i], i);
            path[i] = prevIndex;
        } else {
            *it = p(arr[i], i);
            if (it != v.begin()) {
                it--;
                path[i] = (*it).second;
            } else {
                path[i] = -1;
            }
        }

    }
    int curr = v.back().second;
    stack<int> pathStack;
    while (curr != -1) {
        pathStack.push(arr[curr]);
        curr = path[curr];
    }
    cout<<pathStack.size()<<'\n';
    while(!pathStack.empty()){
        cout<<pathStack.top()<<' ';
        pathStack.pop();
    }

    return 0;
}