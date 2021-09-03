#include <iostream>

using namespace std;

using ll = long long;
const int MAX = 1<<20;

ll tree[MAX * 2];

void modify(int index){
    if(index==0) return;
    tree[index] = tree[index*2] + tree[index*2+1];
    return modify(index/2);
}

ll sum(int nodeNum, int L, int R, int nodeL, int nodeR){
    if(nodeL>=R || nodeR<=L) return 0ll;
    if(nodeL>=L && nodeR<=R) return tree[nodeNum];
    int mid = (nodeL+nodeR)/2;
    return sum(nodeNum*2, L, R, nodeL, mid) + sum(nodeNum*2+1, L, R, mid, nodeR);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N, M;
    cin>>N>>M;

    for (int i = 0, q, l, r; i < M; ++i) {
        cin>>q>>l>>r;
        if(q==1){
            // modify
            tree[MAX + l - 1] = r;
            modify((MAX + l - 1)/2);
        }else{
            // print sum of arr[l:r]
            if(l>r) swap(l, r);
            cout<<sum(1, l-1, r, 0, MAX)<<'\n';
        }
    }

    return 0;
}