#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

string calcGrade(float totalScore){
    if(totalScore >= 90.0){
        return "A";
    }else if(totalScore >= 80.0){
        return "B";
    }else if(totalScore >= 70){
        return "C";
    }else if(totalScore >= 50){
        return "D";
    }else{
        return "F";
    }
}

string solution(vector<vector<int>> scores) {
    int n = (int)scores.size();
    vector<vector<int>> temp(n, vector<int>(n));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            temp[j][i] = scores[i][j];
        }
    }
    string answer = "";
    int index = 0;
    for(auto score: temp){
        map<int, int> temp;
        for(auto x:score){
            temp[x]++;
        }
        if(temp[score[index]]==1&&(score[index]==*max_element(score.begin(), score.end())||score[index]==*min_element(score.begin(), score.end()))){
            answer += calcGrade((float)(accumulate(score.begin(), score.end(), 0)-score[index])/(int)(score.size()-1));
        }else{
            answer += calcGrade((float)accumulate(score.begin(), score.end(), 0)/(int)(score.size()));
        }
        index++;
    }
    return answer;
}