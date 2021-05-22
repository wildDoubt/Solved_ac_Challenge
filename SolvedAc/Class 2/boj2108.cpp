#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;
using p = pair<int, int>;
using ll = long long;
const int MAX = 10e+6;
const int INF = 0x66554433;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<int> median;

int main(){
    Quick_IO();
    int N;
    cin>>N;
    ll sum = 0;
    int minValue = INF;
    int maxValue = -INF;

    map<int, int> arr;
    for (int i = 0; i < N; ++i) {
        int a;
        cin>>a;
        sum+=a;
        median.push_back(a);
        minValue = min(minValue, a);
        maxValue = max(maxValue, a);
        arr[a]++;
    }
    sort(median.begin(), median.end());
    if(abs(sum%N)>N/2){
        if(sum>0) cout<<sum/N+1<<endl;
        else cout<<sum/N-1<<endl;
    }else{
        cout<<sum/N<<endl;
    }
    cout<<median[N/2]<<endl;
    vector<p> counts(arr.begin(), arr.end());
    sort(counts.begin(), counts.end(), [](p a, p b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second>b.second;
    });
    if(counts.size()>1){
        if(counts[0].second!=counts[1].second){
            cout<<counts[0].first<<endl;
        }else{
            cout<<counts[1].first<<endl;
        }
    }else{
        cout<<counts[0].first<<endl;
    }
    cout<<maxValue-minValue<<endl;
    return 0;
}