#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    int left = k;
    string answer = "";
    for(int i = 0;i<(int)number.size();i++){
        bool flag = true;
        for(int j = left;j>0;j--){
            if(i+j>=(int)number.size()){
                flag=false;
                break;
            }
            if(number[i+j]-'0'>number[i]-'0'){
                flag = false;
                break;
            }
        }
        if(flag){
            answer += number[i];
        }else{
            left--;
        }
    }
    return answer;
}