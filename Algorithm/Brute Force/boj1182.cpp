#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <set>

using namespace std;

const int MAX = 10e+6;
const int INF = 0x66554433;

int arr[21];
int answer;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    Quick_IO();
    int n, s;
    cin>>n>>s;
    for (int i = 0; i < n; ++i) cin>>arr[i];

    for(int k = 0;k<n;k++) {
        vector<bool> comb(n-k, true);
        for(int j = 0;j<k;j++) comb.push_back(false);
        do {
            int tempSum = 0;
            for (int i = 0; i < n; i++) {
                if (comb[i])
                    tempSum += arr[i];
            }
            if (tempSum == s) answer++;
        } while (prev_permutation(comb.begin(), comb.end()));
    }
    cout<<answer<<"\n";

    return 0;
}