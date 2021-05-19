#include <iostream>
#include <algorithm>

using namespace std;

inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool arr[2187][2187];

void calc(int x1, int y1, int x2, int y2){
    if(x1+1==x2 && y1+1==y2){
        if(x1%3!=1||y1%3!=1) {
            arr[x1][y1] = true;
        }
        return;
    }
    int d = (x2-x1)/3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(i==1&&j==1) continue;
            int new_x1 = x1+i*d;
            int new_y1 = y1+j*d;
            int new_x2 = x1+(i+1)*d;
            int new_y2 = y1+(j+1)*d;
            calc(new_x1, new_y1, new_x2, new_y2);
        }
    }
}

int main(){
    quick_IO();
    int N;
    cin>>N;
    calc(0, 0, N, N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if(arr[i][j]) cout<<"*";
            else cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}