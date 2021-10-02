#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N;
    cin>>N;
    int arr[N];
    for(int &x: arr) cin>>x;
    sort(arr,arr+N);

    int minValue = abs(arr[0] + arr[N-1]);
    int answer1=arr[0], answer2=arr[N-1];
    int p=0,q=N-1;

    while(p<q){
        int temp = arr[p]+arr[q];
        if(minValue>abs(temp)){
            minValue = abs(temp);
            answer1 = arr[p];
            answer2 = arr[q];
        }
        if(temp>0) q--;
        else p++;
    }
    if(answer1>answer2) swap(answer1, answer2);
    cout<<answer1<<' '<<answer2<<'\n';

    return 0;
}