#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int INF = 0x66554433;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    Quick_IO();
    int t;
    cin >> t;
    while (t--) {
        int n, odd=0, even=0;
        cin>>n;
        int arr[n];
        // 1은 0101...일 때, 2는 1010...일 때
        deque<int> oddQ1, oddQ2;
        deque<int> evenQ1, evenQ2;
        for (int i = 0, num; i < n; ++i) {
            cin>>num;
            arr[i] = num%2;

            if(i%2!=arr[i]){
                if(arr[i]%2==1){
                    evenQ1.push_back(i);
                }else{
                    oddQ1.push_back(i);
                }
            }

            if((i+1)%2!=arr[i]){
                if(arr[i]%2==1){
                    evenQ2.push_back(i);
                }else{
                    oddQ2.push_back(i);
                }
            }

            if(num%2==1) {
                odd++;
            }
            else{
                even++;
            }
        }

        if(abs(odd-even)>1){
            cout<<-1<<'\n';
            continue;
        }
        int answer1 = 0, answer2 = 0;
//        cout<<"even: ";
//        for(auto x: evenQ1) cout<<x<<' ';
//        cout<<'\n';
//        cout<<"odd: ";
//        for(auto x: oddQ1) cout<<x<<' ';
//        cout<<'\n';
//
//        cout<<"even: ";
//        for(auto x: evenQ2) cout<<x<<' ';
//        cout<<'\n';
//        cout<<"odd: ";
//        for(auto x: oddQ2) cout<<x<<' ';
//        cout<<'\n';
        // 1로 시작
        if(evenQ2.size()==oddQ2.size()){
            int size = (int)evenQ2.size();
            for (int i = 0; i < size; ++i) {
                answer2+=abs(evenQ2[i] - oddQ2[i]);
            }
        }else{
            answer2 = INF;
        }

        if(evenQ1.size()==oddQ1.size()){
            int size = (int)evenQ1.size();
            for (int i = 0; i < size; ++i) {
                answer1+=abs(evenQ1[i] - oddQ1[i]);
            }
        }else{
            answer1 = INF;
        }
        // 0으로 시작
        cout<<min(answer1, answer2)<<'\n';

    }

    return 0;
}