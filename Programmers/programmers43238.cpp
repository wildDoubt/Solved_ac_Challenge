#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const ll MAX = (ll)1e9;

ll solution(int n, vector<int> times) {
    ll answer;
    sort(times.begin(), times.end());
    ll left=1, right=min((ll)times.front(), MAX)*(ll)n;
    answer = right;

    while(left<=right){
        ll mid = (left+right)/2ll;
        ll result = 0;

        for(int time:times){
            result += mid/time;
        }

        if(result>=n){
            answer = min(answer, mid);
            right = mid-1;
        }else if(result<n){
            left = mid+1;
        }
    }
    return answer;
}

int main(){
    string a;
    cout<<solution(6, vector<int>{7, 10})<<endl;
    cout<<solution(3, vector<int>{1, 99,99})<<endl;
    cout<<solution(3, vector<int>{1, 1,1})<<endl;
    cout<<solution(3, vector<int>{1, 2,3})<<endl;
    cout<<solution(100000, vector<int>{1000000000, 999999999,999999998})<<endl;
    cout<<solution(2, vector<int>{1, 2})<<endl;
    return 0;
}