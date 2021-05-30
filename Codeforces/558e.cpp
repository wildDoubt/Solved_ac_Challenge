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

inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

typedef struct node{
    int l;
    int r;
    int count;
    int lazy; // -1이면 글자를 다 안 채웠다는 뜻, 1이면 글자를 다 채웠다는 뜻
} node;

node tree[26][400005];
string a;
int pullup(int t, int node){
    tree[t][node].count = tree[t][node*2].count + tree[t][node*2+1].count;
    return 0;
}
int build(int t, int node, int left, int right){
    int mid;
    tree[t][node].l = left;
    tree[t][node].r = right;
    tree[t][node].lazy = -1;
    if(left==right){
        if(a[left]-'a'==t){
            tree[t][node].count = 1;
        }else{
            tree[t][node].count = 0;
        }
        return 0;
    }
    mid = (left+right)/2;
    build(t, node*2, left, mid);
    build(t, node*2+1, mid+1, right);
    pullup(t, node);
    return 0;
}

int push_down(int t, int node){
    int lazy = tree[t][node].lazy;
    if(lazy==1){
        tree[t][node*2].lazy = 1;
        tree[t][node*2].count = tree[t][node*2].r - tree[t][node*2].l + 1;
        tree[t][node*2+1].lazy = 1;
        tree[t][node*2+1].count = tree[t][node*2+1].r - tree[t][node*2+1].l + 1;
    }else if(lazy == 0){
        tree[t][node*2].lazy = 0;
        tree[t][node*2].count = 0;
        tree[t][node*2+1].lazy = 0;
        tree[t][node*2+1].count = 0;
    }
    tree[t][node].lazy = -1;
}

int query(int t, int node, int left, int right){
    int lret, rret;
    if(tree[t][node].l>=left && tree[t][node].r<=right){
        return tree[t][node].count;
    }
    if(tree[t][node].l>right || tree[t][node].r<left) return 0;
    push_down(t, node); // lazy를 해소하고 내려감

    lret = query(t, node*2, left, right);
    rret = query(t, node*2+1, left, right);
    return lret + rret;
}

int update(int t, int node, int left, int right, int v){
    if(tree[t][node].l>=left && tree[t][node].r<=right){
        if(v==1){
            tree[t][node].count = tree[t][node].r - tree[t][node].l + 1;
            tree[t][node].lazy = 1;
        }else{
            tree[t][node].count = 0;
            tree[t][node].lazy = 0;
        }
        return 0;
    }
    if(tree[t][node].l>right || tree[t][node].r<left) return 0;
    push_down(t, node);
    update(t, node*2, left, right, v);
    update(t, node*2+1, left, right, v);
    pullup(t, node);
    return 0;
}

int main(){
    quick_IO();
    int n, q;
    string temp;
    int num[26];
    cin>>n>>q;

    cin>>temp;
    a = " "+temp;
    int start;
    for(int i = 0;i<26;i++){
        build(i, 1, 1, n);
    }
    for(int i = 0;i<q;i++){
        int l, r, v;
        cin>>l>>r>>v;
        for(int j = 0;j<26;j++){
            num[j] = query(j, 1, l, r);
            update(j, 1, l, r, 0);
        }
        if(v==1){
            // 오름차순
            start = l;
            for(int j = 0;j<26;j++){
                if(num[j]>0){
                    update(j, 1, start, start+num[j]-1, 1);
                }
                start += num[j];
            }
        }else{
            // 내림차순
            start = l;
            for(int j = 0;j<26;j++){
                if(num[25-j]>0){
                    update(25-j, 1, start, start+num[25-j]-1, 1);
                }
                start += num[25-j];
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<26;j++){
            if(query(j, 1, i, i)==1){
                cout<<(char)('a'+j);
            }
        }
    }
    cout<<"\n";
    return 0;
}