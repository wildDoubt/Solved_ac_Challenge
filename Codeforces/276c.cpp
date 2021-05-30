#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using p = pair<int, int>;

const int INF = 0x66554433;
typedef struct node{
    int l;
    int r;
    int val;
}node;
node tree[800005];
int update(int nd, int left, int right){
    if(tree[nd].l>=left && tree[nd].r<=right){
        tree[nd].val += 1;
    }
    if(tree[nd].l>right || tree[nd].r<left){
        return 0;
    }
    int mid = (left + right)/2;
    update(nd, left, mid);
    update(nd, mid+1, right);
    return 0;
}
int build(int nd, int left, int right){
    cout<<nd<<" build\n";
    tree[nd].l = left;
    tree[nd].r = right;
    if(left==right){
        tree[nd].val = 1;
        return 0;
    }
    int mid = (left+right)/2;
    build(nd, left, mid);
    build(nd, mid+1, right);
    return 0;
}
int query(int nd, int left, int right){
    if(tree[nd].l>=left && tree[nd].r<=right){
        return tree[nd].val;
    }
    if(tree[nd].l>right || tree[nd].r<left){
        return 0;
    }
    int mid = (left + right)/2;
    int ret1 = query(nd, left, mid);
    int ret2 = query(nd, mid+1, right);
    return ret1+ret2;
}
inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int arr[200005];

int main(){
    quick_IO();
    int n, q;
    int l, r;
    cin>>n>>q;
    build(1, 1, n);
    for(int i = 0;i<n;i++) cin>>arr[i];
    for(int i = 1;i<=q;i++){
        cin>>l>>r;
        update(i, l, r);
    }

    return 0;
}