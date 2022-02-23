#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
using p = pair<int, int>;
using ll = long long;
const int MAX = 10e+6;
const int INF = 0x66554433;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    int size = (int) enroll.size();
    vector<int> answer(size);
    unordered_map<string, int> index;
    // 이익 계산한 값을 answer에 넣기 위해 enroll에서 사람의 인덱스를 찾아야 한다.
    // map을 이용하여 (이름, index)형태로 index를 저장한다. => 빠르게 인덱스를 찾기 위해서 사용 O(NlogN)
    for (int i = 0; i < size; ++i) {
        index[enroll[i]] = i;
    }

    // seller를 순차적으로 본다.

    // amount*10은 parent로 올라간다. 만약 amount*0.1이 10보다 작으면 올라가지 않는다. O(NlogN)
    // currIndex = index[seller], parentIndex = index[referral[currIndex]]
    for (int i = 0; i < (int) seller.size(); ++i) {
        string curr = seller[i];
        int currIndex = index[seller[i]];
        string parent = referral[currIndex];
        // 현재 amount*90은 index[seller]에 추가한다.
        // 만약 parent가 없으면 추가하고 끝낸다.
        if (parent == "-") {
            answer[currIndex] += amount[i] * 90;
            continue;
        }

        int profit = amount[i] * 100;
        // curr에서 parent로 올라가면서 더한다.
        // 현재 이익이 0인 경우는 아래 노드가 나누어줄 돈이 없기 때문에 아래 노드가 전부 가져간 경우이다.
        // 따라서 해당 경우에는 반복문을 빠져 나온다.
        // answer[currIndex]에 현재 이익의 90%를 더한다.
        // 나머지 10%는 위로 보낸다.
        while (curr != "-") {
            int parentProfit = profit / 10;
            if (profit == 0) break;

            currIndex = index[curr];
            answer[currIndex] += (profit - parentProfit);

            profit = parentProfit;
            parent = referral[currIndex];
            curr = parent;
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> answers;
    answers.push_back(solution(vector<string>{"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"},
                               vector<string>{"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"},
                               vector<string>{"young", "john", "tod", "emily", "mary"},
                               vector<int>{12, 4, 2, 5, 10}));
    answers.push_back(solution(vector<string>{"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"},
                               vector<string>{"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"},
                               vector<string>{"sam", "emily", "jaimie", "edward"},
                               vector<int>{2, 3, 5, 4}));
    for (const auto &answer:answers) {
        for (auto x:answer) {
            cout << x << " ";
        }
        cout << endl;
    }


    return 0;
}