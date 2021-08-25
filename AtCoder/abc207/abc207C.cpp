#include <iostream>
#include <algorithm>

using namespace std;
using pd = pair<double, double>;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

pd arr[2001];

int main() {
    Quick_IO();
    int N;
    cin >> N;

    for (int i = 1, t; i <= N; ++i) {
        double l, r;
        cin >> t >> l >> r;
        if(t==2){
            r-=0.5;
        }else if (t==3){
            l+=0.5;
        }else if(t==4){
            r-=0.5;
            l+=0.5;
        }

        arr[i] = pd(l, r);
    }
    int answer = 0;

    for (int i = 1; i <= N; ++i) {
        double left1 = arr[i].first, right1 = arr[i].second;
        for (int j = i+1; j <= N; ++j) {
            double left2 = arr[j].first, right2 = arr[j].second;
            double L = max(left1, left2);
            double R = min(right1, right2);
            if(L<=R){
                answer++;
            }
        }
    }

    cout<<answer<<'\n';

    return 0;
}