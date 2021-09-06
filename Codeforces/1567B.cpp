#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        // a는 배열에 없는 수 중 가장 작은 자연수
        // b는 모든 배열을 XOR 연산했을 때 나타나는 수
        // 100 1
        int temp;
        if(a==1){
            temp = 0;
        }else if(a==2){
            temp = 1;
        }else if(a==3){
            temp = 3;
        }else{
            if(a%4==0){
                temp = 0;
            }else if(a%4==1){
                temp = a-1;
            }else if(a%4==2){
                temp = 1;
            }else {
                temp = a;
            }
        }
        if(temp == b){
            cout<<a;
        }else{
            if((temp ^ b)==a){
                cout<<a+2;
            }else{
                cout<<a+1;
            }

        }
        cout<<'\n';

    }

    return 0;
}