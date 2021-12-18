#include <iostream>

using namespace std;
const int MAX = 1e4;

int arr[MAX];

void postOrder(int s, int e){
    if(s + 1 == e){
        cout<<arr[s]<<'\n';
        return;
    }

    int right = s;
    while(right < e && arr[right] <= arr[s]){
        right++;
    }

    if(s+1<right)
        postOrder(s + 1, right);
    if(right < e)
        postOrder(right, e);
    cout<<arr[s]<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int input;
    int index = 0;

    while (cin >> input) {
        arr[index++] = input;
    }

    postOrder(0, index);

    return 0;
}