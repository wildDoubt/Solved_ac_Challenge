#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e6 + 5;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int arr[MAX];

// merge 직접 구현
int leftArr[MAX / 2];
int rightArr[MAX / 2];

void mergeArray(int s, int mid, int e) {
    // s ~ mid
    // mid+1 ~ e
    int leftSize = mid - s;
    int rightSize = e - mid;

    for (int i = 0; i < leftSize; ++i) {
        leftArr[i] = arr[s + i];
    }

    for (int i = 0; i < rightSize; ++i) {
        rightArr[i] = arr[i + mid];
    }

    int l = 0, r = 0, index = s;
    while (l != leftSize && r != rightSize) {
        if (leftArr[l] <= rightArr[r]) {
            arr[index] = leftArr[l++];
        } else {
            arr[index] = rightArr[r++];
        }
        index++;
    }

    while (l < leftSize) {
        arr[index++] = leftArr[l++];
    }

    while (r < rightSize) {
        arr[index++] = rightArr[r++];
    }
}

void partition(int s, int e) {
    if (s+1 >= e) return;
    int mid = (s + e) / 2;
    partition(s, mid);
    partition(mid, e);
    // mergeArray(s, mid, e);
    int temp[e-s];
    merge(arr+s, arr+mid, arr+mid, arr+e, temp);
    for (int i = s; i < e; ++i) {
        arr[i] = temp[i-s];
    }
}

int main() {
    Quick_IO();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    partition(0, n);
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << '\n';
    }
    return 0;
}