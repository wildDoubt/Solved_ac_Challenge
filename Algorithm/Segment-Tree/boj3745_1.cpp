// segment tree

#include <iostream>
#include <algorithm>

using namespace std;
using p = pair<int, int>;
const int MAX = 1 << 17;

int n, tree[MAX * 2];

void update(int index) {
    if (index == 0) return;
    tree[index] = max(tree[index * 2], tree[index * 2 + 1]);
    return update(index / 2);
}

int calc(int nodeNum, int L, int R, int nodeL, int nodeR){
    if(nodeL>=R || nodeR<=L) return 0ll;
    if(nodeL>=L && nodeR<=R) return tree[nodeNum];
    int mid = (nodeL+nodeR)/2;
    return max(calc(nodeNum*2, L, R, nodeL, mid), calc(nodeNum*2+1, L, R, mid, nodeR));
}

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr), cout.tie(nullptr);

    while (true) {
        cin >> n;
        if (cin.eof()) break;
        vector<p> arr(n);
        for (int i = 0, input; i < n; ++i) {
            cin >> input;
            arr[i] = {i, input};
        }
        sort(arr.begin(), arr.end(), [](p a, p b){
            if(a.second==b.second){
                return a.first>b.first;
            }
            return a.second<b.second;
        });
//        for(auto x: arr){
//            cout<<x.first<<" "<<x.second<<'\n';
//        }
        for (int i = 0; i < n; ++i) {
            int index = arr[i].first;
            tree[MAX+index] = calc(1, 0, index, 0, MAX) + 1;
            update((MAX+index)/2);
        }

        cout<<tree[1]<<'\n';
        for (int i = 0; i < n; ++i) {
            tree[MAX + i] = 0;
            update((MAX+i)/2);
        }
    }

    return 0;
}