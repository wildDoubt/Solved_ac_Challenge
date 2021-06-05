#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int partition(int* arr, int left, int right){
    int pivot = arr[left];
    int i = left;
    int j = right;
    while(i<j){
        while(pivot<arr[j]){
            j--;
        }
        while(i<j&&pivot>=arr[i]){
            i++;
        }
        swap(arr[i], arr[j]);
    }
    arr[left] = arr[i];
    arr[i] = pivot;
    return i;
}

void quickSort(int* arr, int left, int right) {
    if(left>=right){
        return;
    }
    int pivot = partition(arr, left, right);
    quickSort(arr, left, pivot-1);
    quickSort(arr, pivot+1, right);
}


int main(){
    Quick_IO();
    int N;
    cin>>N;
    int arr[N+1];
    for (int i = 0; i < N; ++i) {
        cin>>arr[i];
    }
    random_device rd;
    shuffle(arr, arr+N, default_random_engine(rd()));
    quickSort(arr, 0, N-1);
    for (int i = 0; i < N; ++i) {
        cout<<arr[i]<<"\n";
    }
    return 0;
}

