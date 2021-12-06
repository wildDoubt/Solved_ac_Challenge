#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N, maxValue = INT32_MIN, minValue = INT32_MAX, positiveD = 1, negativeD = 1;
    vector<int> positiveArr;
    vector<int> negativeArr;
    cin >> N;

    for (int i = 0, input; i < N; ++i) {
        cin >> input;
        if(input>=0) positiveArr.push_back(input);
        else negativeArr.push_back(input);
        maxValue = max(maxValue, input);
        minValue = min(minValue, input);
    }
    while (maxValue >= 10) {
        maxValue /= 10;
        positiveD *= 10;
    }
    while (minValue <= -10) {
        minValue /= 10;
        negativeD *= 10;
    }
    cout << "negativeD: " << negativeD << '\n';
    cout << "positiveD: " << positiveD << '\n';
    queue<int> negativeBucket[10];
    queue<int> positiveBucket[10];

    for (int i = 1; i <= positiveD; i *= 10) {
        for(int positiveValue: positiveArr){
            int index = (positiveValue / i) % 10;
            positiveBucket[index].push(positiveValue);
        }
        int index = 0;
        for (int j = 0; j < 10; ++j) {
            while (!positiveBucket[j].empty()) {
                positiveArr[index++] = positiveBucket[j].front();
                positiveBucket[j].pop();
            }
        }
    }

    for (int i = 1; i <= negativeD; i *= 10) {
        for(int negativeValue: negativeArr){
            int index = (-negativeValue / i) % 10;
            negativeBucket[index].push(negativeValue);
        }
        int index = 0;
        for (int j = 9; j >=0; --j) {
            while (!negativeBucket[j].empty()) {
                negativeArr[index++] = negativeBucket[j].front();
                negativeBucket[j].pop();
            }
        }
    }

    for(int negativeValue: negativeArr){
        cout<<negativeValue<<'\n';
    }

    for(int positiveValue: positiveArr){
        cout<<positiveValue<<'\n';
    }
    return 0;
}