#include <iostream>
#include <algorithm>

using namespace std;

bool match(const string& input, const string& pattern, int index){
    int size = (int) pattern.size();
    for (int i = 0; i < size; ++i) {
        if(input[index+i]!=pattern[i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    string input, pattern;
    getline(cin, input);
    getline(cin, pattern);

    int answer = 0, index = 0;
    int patternSize = (int) pattern.size();
    int inputSize = (int) input.size();

    while(index < inputSize){
        if(match(input, pattern, index)){
            ++answer;
            index += patternSize;
        }else{
            ++index;
        }
    }

    cout << answer << '\n';

    return 0;
}