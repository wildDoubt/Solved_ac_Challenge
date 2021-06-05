#include <iostream>
#include <algorithm>

using namespace std;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void merge(int arr[], int l, int m, int r){
    int k;
    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[l+i];
    }
    for (int i = 0; i < n2; ++i) {
        R[i] = arr[m+i+1];
    }

    int i=0, j=0;
    k = l;

    while(i<n1&&j<n2){
        if(L[i]<=R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while(i<n1) arr[k++] = L[i++];

    while(j<n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right){
    if(left>=right) return;
    int mid = (left+right)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main(){
    Quick_IO();
    int N;
    cin>>N;
    int arr[N+1];
    for (int i = 0; i < N; ++i) {
        cin>>arr[i];
    }
    mergeSort(arr, 0, N-1);
    for (int i = 0; i < N; ++i) {
        cout<<arr[i]<<"\n";
    }
    return 0;
}

