#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    Quick_IO();
    int n, maxScore = 0, totalSum = 0;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin>>a;
        totalSum += a;
        maxScore = max(a, maxScore);
    }
    cout<<fixed<<setprecision(3)<<100*(double)totalSum/maxScore/n<<"\n";
    return 0;
}