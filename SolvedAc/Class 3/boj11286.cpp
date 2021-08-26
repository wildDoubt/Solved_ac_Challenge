#include <iostream>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int arr[1 << 18];
int last = 1;

struct cmp {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
} cmp;

void push(int a) {
    arr[last++] = a;
    int index = last - 1;
    while (index > 1) {
        if (cmp(arr[index / 2], arr[index])) {
            swap(arr[index], arr[index / 2]);
        }
        index /= 2;
    }
}

int pop() {
    if(last==1) return 0;

    int ret = arr[1];

    arr[1] = arr[last - 1];
    arr[last - 1] = INT32_MAX;
    last--;
    int index = 1;
    while (index < last) {
        int leftValue = arr[index * 2];
        int rightValue = arr[index * 2 + 1];

        if (cmp(leftValue, arr[index]) && cmp(rightValue, arr[index])) break;
        else {
            if (cmp(leftValue, rightValue)) {
                swap(arr[index], arr[index * 2 + 1]);
                index = index * 2 + 1;
            } else {
                swap(arr[index], arr[index * 2]);
                index *= 2;
            }
        }
    }

    return ret;
}

int main() {
    Quick_IO();
    int N, input;
    cin >> N;
    fill(arr, arr + (1 << 18), INT32_MAX);
    while (N--) {
        cin >> input;
        if (input != 0) push(input);
        else cout << pop() << '\n';
    }

    return 0;
}