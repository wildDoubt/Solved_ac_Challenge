#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int num[9] = {0,};
    int answer = 0;
    string input;
    cin>>input;

    for(char ch:input){
        if(ch=='9'||ch=='6'){
            num[6]++;
            continue;
        }
        num[ch-'0']++;
        answer = max(answer, num[ch-'0']);
    }
    if(num[6]%2==1) num[6] = num[6]/2+1;
    else num[6]/=2;
    cout<<max(answer, num[6])<<'\n';
    return 0;
}