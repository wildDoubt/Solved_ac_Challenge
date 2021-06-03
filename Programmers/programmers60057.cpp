#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int calc(const string& a, int k){
    string prev;
    int answer = 0;
    int counts = 1;
    for(int i = 0;i<(int)a.size();i+=k){
        string t = a.substr(i, min(k, (int)a.size()-i));
        cout<<t<<endl;
        if(t!=prev){
            answer+=(int)t.size();
            prev = t;
            counts=1;
            continue;
        }
        if(t==prev){
            if(counts==1){
                answer++;
            }
            if(counts==9){
                answer++;
            }
            counts++;
        }
    }
    return answer;
}

int solution(string s) {
    int answer = (int)s.size();
    for(int i = 1;i<=(int)s.size();i++){
        answer = min(answer, calc(s, i));
    }
    return answer;
}

int main(){
    string a;
    cout<<solution(a)<<endl;
    return 0;
}