#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", arr+i);
    }
    sort(arr, arr+N);
    for (int i = 0; i < N; ++i) {
        printf("%d\n", arr[i]);
    }
    return 0;
}