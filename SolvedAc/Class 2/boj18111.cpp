#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;
const ll INF = 10e+15;

int board[500][500];
ll t = INF, answer;

int main(){
    int N, M, B;
    cin>>N>>M>>B;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin>>board[i][j];
        }
    }

    for (int k = 0; k <= 256; ++k) {
        ll temp = 0;
        ll tempB = B;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int d = board[i][j] - k;
                if(d>0){
                    temp += 2*d;
                    tempB+=d;
                }else if(d<0){
                    temp -= d;
                    tempB+=d;
                }
            }
        }
        if(tempB>=0){
            if(t>=temp) {
                t = temp;
                answer = k;
            }
        }
    }
    cout<<t<<" "<<answer<<"\n";


    return 0;
}