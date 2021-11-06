/*
1. x번 바꿨을 때 만들 수 있는 수들을 set으로 저장
2. 한 번 바꿔서 만들 수 있는 수는 set[1]에 넣음
3. 두 번 바꿔서 만들 수 있는 수는 set[1]에서 꺼내온 수들을 조건에 맞게 전부 바꿔본다.

그러면 매번 중복되는 계산을 피할 수 있기 때문에 brute force로 탐색하는 15^9보다 작지 않을까????

* 주의할 점
1. N의 길이가 1일 때는 항상 -1이다.
2. 0이 맨 앞으로 오는 경우는 바꾸지 않는다.
3. 한 번도 바꾸지 않으면 -1이다.
*/

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set<string> check[11];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    string N;
    int K;
    bool isPossible = false;
    cin>>N>>K;

    if(N.size()==1){
        cout<<-1<<'\n';
        return 0;
    }

    check[0].insert(N);

    for (int i = 1; i <= K; ++i) {
        // check[i-1]에서 한 번씩 바꾼 걸 넣음
        int length = (int)N.size();

        for(const string& temp: check[i-1]){
            for (int j = 0; j < length; ++j) {
                for (int k = j+1; k < length; ++k) {
                    if(N[k]=='0' && j==0) continue;
                    string tempN = temp;
                    isPossible = true;
                    swap(tempN[j], tempN[k]);
                    check[i].insert(tempN);
                }
            }
        }
    }

    if(!isPossible) cout<<-1;
    else{
        int answer = INT32_MIN;
        for(const auto& x:check[K]) answer = max(answer, stoi(x));
        cout<<answer;
    }
    cout<<'\n';

    return 0;
}