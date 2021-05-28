#include <iostream>
#include <algorithm>

using namespace std;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    Quick_IO();
    int N;
    cin>>N;
    int m2[501] = {0, };
    int m5[501] = {0, };
    for (int i = 2; i <= N; i*=2) {
        for (int j = i; j <= N; j+=i) {
            m2[j]++;
        }
    }
    for (int i = 5; i <= N; i*=5) {
        for (int j = i; j <= N; j+=i) {
            m5[j]++;
        }
    }
    int two = 0;
    int five = 0;
    for (int i = 0; i <= N; ++i) {
        two += m2[i];
        five += m5[i];
    }
    cout<<min(two, five)<<"\n";
    return 0;
}