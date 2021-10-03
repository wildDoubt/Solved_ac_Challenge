#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N;
    cin>>N;
    int arr[N], answer1, answer2, answer3;
    ll minValue = LONG_LONG_MAX;

    for (int i = 0; i < N; ++i) {
        cin>>arr[i];
    }

    sort(arr, arr+N);
//    for (int i = 0; i < N; ++i) {
//        cout<<arr[i]<<' ';
//    }
//    cout<<'\n';
    for (int i = 0; i < N; ++i) {
        int p, q, r = i;
        if(r==0) p=1;
        else p=0;
        if(r==N-1) q=N-2;
        else q=N-1;
//        minValue = abs(arr[p] + arr[q] + arr[i]);
//        answer1=arr[p];
//        answer2=arr[q];
//        answer3=arr[i];

        while(p<q){
            ll temp = (ll)arr[i] + arr[p] + arr[q];
//            cout<<p<<' '<<q<<' '<<r<<" compare\n";
            if(minValue>abs(temp)){
                minValue = abs(temp);
                answer1=arr[p];
                answer2=arr[q];
                answer3=arr[i];
            }
            if(temp<0ll){
                p++;
                if(p==i) p++;
            }else{
                q--;
                if(q==i) q--;
            }
        }
    }
    vector<int> answers(3);
    answers[0] = answer1;
    answers[1] = answer2;
    answers[2] = answer3;
    sort(answers.begin(), answers.end());
    for(auto answer:answers) cout<<answer<<' ';
    cout<<'\n';
    return 0;
}