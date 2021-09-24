#include <iostream>

using namespace std;

const int MAX = 1<<17;

int tree[MAX*2+5];

void update(int index){
    if(index<=1) return;
    tree[index] = tree[index*2] + tree[index*2+1];
    update(index/2);
}

int query(int num, int L, int R, int l, int r){
    if(L>=r || R<=l) return 0;
    if(l>=L && r<=R) return tree[num];
    int mid = (l+r)/2;
    return query(num*2, L, R, l, mid) + query(num*2+1, L, R, mid, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N;
    cin>>N;
    int arr[N];

    for (int i = MAX; i < 2*MAX; ++i) {
        tree[i] = 1;
        update(i/2);
    }
    // 1이 루트, MAX부터 입력받은대로 기록
    for (int i = 0, index; i < N; ++i) {
        cin>>index;
        arr[index-1] = i;
    }
    int start = 1, end = N;

    while(start<end){
        // [0, arr[start-1])
        cout<<query(1, 0, arr[start-1], 0, MAX)<<'\n';
        tree[MAX+arr[start-1]] = 0;
        update((MAX+arr[start-1])/2);
        start++;

        // [arr[end]+1, N)
        cout<<query(1, arr[end-1]+1, N, 0, MAX)<<'\n';
        tree[MAX+arr[end-1]] = 0;
        update((MAX+arr[end-1])/2);
        end--;
    }

    if(start==end){
        cout<<query(1, 0, arr[start-1], 0, MAX)<<'\n';
    }

    return 0;
}