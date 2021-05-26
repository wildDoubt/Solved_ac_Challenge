#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e5 + 5;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int inorder[MAX];
int postorder[MAX];
// 인오더: 왼-중-오
// 포스트오더: 왼-오-중
// 프리오더: 중-왼-오
// 6 2 1 4 3 5
// 6 2 4 5 3 1
// 1 6 2 3 4 5

void preorder(int pl, int pr, int il, int ir) {
    if (il > ir || pl > pr) return;
    cout << postorder[pr] << " ";
    int im = find(inorder + il, inorder + ir, postorder[pr]) - inorder;
    int d = im - il-1;

    preorder(pl, pl + d, il, im -1);
    preorder(pl + d+1, pr-1, im + 1, ir);

}

int main() {
    Quick_IO();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> inorder[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> postorder[i];
    }
    preorder(0, n - 1, 0, n - 1);
    cout<<"\n";
    return 0;
}