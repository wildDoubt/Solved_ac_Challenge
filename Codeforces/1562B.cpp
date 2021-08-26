#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e3+2;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<bool> isPrime;
vector<int> prime;

int main() {
    Quick_IO();
    int t;
    cin >> t;

    isPrime.resize(MAX + 1);
    fill(isPrime.begin(), isPrime.end(), true);
    prime.push_back(2);
    for (int i = 4; i <= MAX; i += 2)
        isPrime[i] = false;
    for (int i = 3; i <= MAX; i++) {
        if (isPrime[i]) prime.push_back(i);
        for (int j = i * i; j <= MAX; j += i * 2)
            isPrime[j] = false;
    }
    isPrime[1] = false;
    while (t--) {
        string n;
        int k;
        cin >> k >> n;
        bool isOne = false;
        for (int i = 0; i < k; ++i) {
            if(!isPrime[n[i]-'0']){
                cout<<1<<'\n';
                cout<<n[i]<<'\n';
                isOne = true;
                break;
            }
        }
        if(!isOne){
            for (int i = 0; i < k; ++i) {
                bool flag = true;
                for (int j = i+1; j < k; ++j) {
                    int t1 = n[i]-'0', t2 = n[j]-'0';
                    if(!isPrime[(t1*10+t2)]){
                        cout<<2<<'\n';
                        cout<<t1*10+t2<<'\n';
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
            }
        }
    }

    return 0;
}