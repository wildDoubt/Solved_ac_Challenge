#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
using ps = pair<int, string>;
const int MOD = 1e4;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int D(int a) {
    return (a * 2) % MOD;
}

int S(int a) {
    return a-1<0 ? 9999 : a - 1;
}

int L(int a) {
    int d[4];
    for (int i = 3; i >= 0; --i) {
        d[i] = a%10;
        a/=10;
    }
    return 1000*d[1] + 100*d[2]+10*d[3]+d[0];
}

int R(int a) {
    int d[4];
    for (int i = 3; i >= 0; --i) {
        d[i] = a%10;
        a/=10;
    }
    return 1000*d[3] + 100*d[0]+10*d[1]+d[2];
}

int main() {
    Quick_IO();
    int t;
    cin >> t;
    while (t--) {
        int A, B;
        cin >> A >> B;
//        cout<<R(A)<<'\n';
        queue<ps> q;
        q.push(ps(A, ""));
        bool visited[MOD];
        fill(visited, visited+MOD, false);
        while (!q.empty()) {
            auto[curr, currResult] = q.front();
            q.pop();
//            cout<<curr<<" "<<currResult<<'\n';
            if (curr == B) {
                cout << currResult << '\n';
                break;
            }
            int d = D(curr), s = S(curr), l = L(curr), r = R(curr);
            if(!visited[d]){
                q.push(ps(d, currResult + "D"));
                visited[d] = true;
            }
            if(!visited[s]){
                q.push(ps(s, currResult + "S"));
                visited[s] = true;
            }
            if(!visited[l]){
                q.push(ps(l, currResult + "L"));
                visited[l] = true;
            }
            if(!visited[r]){
                q.push(ps(r, currResult + "R"));
                visited[r] = true;
            }
        }
    }

    return 0;
}