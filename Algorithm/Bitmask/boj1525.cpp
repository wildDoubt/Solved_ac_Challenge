#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;
using ll = long long;
const ll ANSWER = 2'271'560'481;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void print(ll status) {
    for (int i = 0; i < 9; ++i) {
        if(i%3==0) cout<<'\n';
        cout<<((status&(15ll<<(i*4)))>>(i*4));
        cout<<" ";
    }
}


ll switchStatus(ll status, int p, int q){
    if(q-p<0) status|=((status&(15ll<<(q*4)))<<((p-q)*4));
    else status|=((status&(15ll<<(q*4)))>>((q-p)*4));

    status&=(-(15ll<<(q*4))-1);
    return status;
}



ll bfs(ll status){
    int counts = 0;
    unordered_set<ll> visited;
    queue<ll> q;
    q.push(status);
    while(!q.empty()){
        int size = (int)q.size();
        for (int i = 0; i < size; ++i) {
            ll curr = q.front();
            q.pop();
            if(curr==ANSWER){
                return counts;
            }
            for (int j = 0; j < 9; ++j) {
                int num = (int)((curr&(15ll<<(j * 4))) >> (j * 4));
                if(num==0){
                    ll newStatus;
                    if((j - 1) % 3 != 2){
                        // 왼쪽
                        newStatus = switchStatus(curr, j, j - 1);
                        if(!visited.count(newStatus)){
                            q.push(newStatus);
                            visited.insert(newStatus);
                        }
                    }
                    if((j - 3) >= 0){
                        // 위쪽
                        newStatus = switchStatus(curr, j, j - 3);
                        if(!visited.count(newStatus)){
                            q.push(newStatus);
                            visited.insert(newStatus);
                        }
                    }
                    if((j + 3) < 9){
                        // 아래쪽
                        newStatus = switchStatus(curr, j, j + 3);
                        if(!visited.count(newStatus)){
                            q.push(newStatus);
                            visited.insert(newStatus);
                        }
                    }
                    if((j + 1) % 3 != 0){
                        // 위쪽
                        newStatus = switchStatus(curr, j, j + 1);
                        if(!visited.count(newStatus)){
                            q.push(newStatus);
                            visited.insert(newStatus);
                        }
                    }
                }
            }
        }
        counts++;
    }


    return -1;
}



int main() {
    Quick_IO();
    ll status = 0;
    for (ll i = 0, input; i < 9; ++i) {
        cin >> input;
        status |= (input << (i * 4));
    }
    cout<<bfs(status)<<'\n';
    return 0;
}