#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using p = pair<ll, ll>; // first: init_value, second: increment
const int MAX = 200000;
const int INF = 0x66554433;

typedef struct RMQ{
    int n;
    vector<p> rangeMin;

    ll init(const vector<ll> &arr, int left, int right, int node) {
        if(left == right) {
            rangeMin[node].second = 0;
            return rangeMin[node].first = arr[left];
        }
        int mid = (left + right)/2;
        ll leftMin = init(arr, left, mid, node*2);
        ll rightMin = init(arr, mid+1, right, node*2+1);
        rangeMin[node].second = 0;
        return rangeMin[node].first = min(leftMin, rightMin);
    }

    RMQ(const vector<ll>& arr){
        n = arr.size();
        rangeMin.resize(n*4);
        init(arr, 0, n-1, 1);
    }

    ll query(int left, int right, int node, int nodeLeft, int nodeRight){
        if(right<nodeLeft||left>nodeRight) return LLONG_MAX;
        if(left<=nodeLeft&&nodeRight<=right) return rangeMin[node].first+rangeMin[node].second;
        int mid = (nodeLeft + nodeRight)/2;
        return min(query(left, right, node*2, nodeLeft, mid),
                   query(left, right, node*2+1, mid+1, nodeRight)) + rangeMin[node].second;
    }
    ll query(int left, int right){
        return query(left, right, 1, 0, n-1);
    }

    ll update(int left, int right, ll val, int node, int nodeLeft, int nodeRight){
        if(right<nodeLeft||left>nodeRight)
            return rangeMin[node].second + rangeMin[node].first;
        if(left<=nodeLeft&&nodeRight<=right){
            rangeMin[node].second += val;
            return rangeMin[node].second + rangeMin[node].first;
        }
        int mid = (nodeLeft + nodeRight)/2;
        rangeMin[node].first = min(
                update(left, right, val, node * 2, nodeLeft, mid),
                update(left, right, val, node * 2 + 1, mid + 1, nodeRight)
                );
        return rangeMin[node].first+rangeMin[node].second;
    }
    ll update(int left, int right, ll newValue){
        return update(left, right, newValue, 1, 0, n-1);
    }
} RMQ;

inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    quick_IO();

    int n, q;
    cin>>n;
    vector<ll> arr;
    for(int i = 0;i<n;i++){
        ll a;
        cin>>a;
        arr.push_back(a);
    }
    RMQ tree(arr);
    cin>>q;
    int lf, rg, v;
    while(q--){
        cin>>lf>>rg;
        if(cin.peek() ==' '){
            cin>>v;
            if(lf<=rg){
                tree.update(lf, rg, v);
            }else{
                tree.update(0, rg, v);
                tree.update(lf, n-1, v);
            }
        } else{
            if(lf<=rg){
                cout<<tree.query(lf, rg)<<"\n";
            }else{
                cout<<min(tree.query(0, rg), tree.query(lf, n-1))<<"\n";
            }
        }
    }
    return 0;
}