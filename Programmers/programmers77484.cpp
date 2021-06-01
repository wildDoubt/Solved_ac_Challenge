// 8분 52초

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2);
    int low=0, zero=0;
    set<int> win{win_nums.begin(), win_nums.end()};
    set<int> candidate;

    for (auto lotto:lottos) {
        if(win.count(lotto)>0){
            low++;
        }
        if(lotto==0){
            zero++;
        }
    }

    answer[0] = (low+zero)>1?7-(low+zero):6;
    answer[1] = low>1?7-low:6;

    return answer;
}

int main(){
    vector<vector<int>> answers;
    answers.push_back(solution(vector<int>{44, 1, 0, 0, 31, 25}, vector<int>{31, 10, 45, 1, 6, 19}));
    answers.push_back(solution(vector<int>{0, 0, 0, 0, 0, 0}, vector<int>{38, 19, 20, 40, 15, 25}));
    answers.push_back(solution(vector<int>{45, 4, 35, 20, 3, 9}, vector<int>{20, 9, 3, 45, 4, 35}));
    for (const auto& answer:answers) {
        for(auto x:answer){
            cout<<x<<" ";
        }
        cout<<endl;
    }


    return 0;
}