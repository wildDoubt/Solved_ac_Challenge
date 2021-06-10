#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, answer = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cin >> x;
    sort(arr, arr + n);
    int l = 0, r = n - 1;
    while (l < r) {
        int tempSum = arr[l] + arr[r];
        if (tempSum == x) {
            l++;
            r--;
            answer++;
        } else if (tempSum > x) {
            r--;
        } else {
            l++;
        }
    }
    cout<<answer<<'\n';
}