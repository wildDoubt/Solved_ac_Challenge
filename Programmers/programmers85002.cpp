#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

using ld = long double;

struct node{
    int index;
    ld winRate;
    int win2;

    node(int a, ld b,int c){
        index = a;
        winRate = b;
        win2 = c;
    }
};

vector<int> solution(vector<int> weights, vector<string> head2head) {
    int size = (int)weights.size();
    vector<node> temp;
    for (int i = 0; i < size; ++i) {
        int win1 = 0, win2 = 0;
        int total = 0;
        for (int j = 0; j < size; ++j) {
            if(head2head[i][j]=='W'){
                win1++;
                if(weights[i]<weights[j]) win2++;
                total++;
            }else if(head2head[i][j]=='L'){
                total++;
            }
        }
        if(total!=0) temp.emplace_back(i, (ld)win1/(ld)total, win2);
        else temp.emplace_back(i, 0.0, win2);
    }
    sort(temp.begin(), temp.end(), [weights](node a, node b){
        if(a.winRate - b.winRate<1e-6){
            if(a.win2==b.win2){
                if(weights[a.index] == weights[b.index]){
                    return a.index<b.index;
                }
                return weights[a.index] > weights[b.index];
            }
            return a.win2>b.win2;
        }
        return a.winRate > b.winRate;
    });
    vector<int> answer(size);
    for (int i = 0; i < size; ++i) {
//        cout<<temp[i].index+1<<": "<<temp[i].winRate<<" "<<temp[i].win2<<'\n';
        answer[i] = temp[i].index+1;
    }
    return answer;
}

int main(){
    vector<int> answer = solution(vector<int>{60,70,60}, vector<string>{"NNN","NNN","NNN"});
    for(auto x: answer){
        cout<<x<<' ';
    }
    return 0;
}