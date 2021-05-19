#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using p = pair<int, int>;

const int INF = 0x66554433;

inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int counts;
int answer;
int n = 1;
int N, r, c;
void calc(int x1, int y1, int x2, int y2){
    if(r>=x1&&r<x2&&c>=y1&&c<y2){
        // 범위 안에 있을 때만 4분할해서 계산한다.
        if(r==x1&&c==y1){
            answer = counts;
            return;
        }
        int d = (x2-x1)/2;
        for(int i = 0;i<2;i++){
            for (int j = 0; j < 2; ++j) {
                int new_x1 = x1+i*d;
                int new_y1 = y1+j*d;
                int new_x2 = x1+(i+1)*d;
                int new_y2 = y1+(j+1)*d;
                calc(new_x1, new_y1, new_x2, new_y2);
            }
        }
    }else{
        // r, c가 범위 안에 없으면 해당 범위만큼 수를 더하고 바로 리턴
        counts += (x2-x1)*(y2-y1);
        return;
    }
}

int main(){
    quick_IO();

    cin>>N>>r>>c;
    while(N--){
        n*=2;
    }
    calc(0, 0, n, n);
    cout<<answer<<endl;
    return 0;
}