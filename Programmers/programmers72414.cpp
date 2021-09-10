#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <limits.h>

using namespace std;
using ll = long long;
const int MAX = 360'001;

int arr[MAX+5];
ll pArr[MAX+5];

int dateToSeconds(const string &date) {
    int hour = stoi(date.substr(0, 2));
    int minute = stoi(date.substr(3, 2));
    int second = stoi(date.substr(6, 2));
    return hour * 3600 + minute * 60 + second;
}

string secondsToDate(int seconds) {
    int hour = seconds / 3600;
    int minute = (seconds - hour * 3600) / 60;
    int second = seconds % 60;
    string result;
    if (hour < 10) result += "0" + to_string(hour) + ":";
    else result += to_string(hour) + ":";
    if (minute < 10) result += "0" + to_string(minute) + ":";
    else result += to_string(minute) + ":";
    if (second < 10) result += "0" + to_string(second);
    else result += to_string(second);
    return result;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    vector<int> starts, ends;
    set<int> test;
    int play_end = dateToSeconds(play_time), adv_length = dateToSeconds(adv_time);
    for (string &log: logs){
        starts.push_back(dateToSeconds(log.substr(0, 8))), ends.push_back(dateToSeconds(log.substr(9, 8)));
        test.insert(dateToSeconds(log.substr(0, 8)));
        test.insert(dateToSeconds(log.substr(9, 8)));
    }

    sort(starts.begin(), starts.end()), sort(ends.begin(), ends.end());
//    for (int i = 0; i < logs.size(); ++i) {
//        cout << starts[i] << " " << ends[i] << '\n';
//    }
    pArr[0] = arr[0];
    for (int i = 0; i <= play_end; ++i) {
//        cout << secondsToDate(i) << " - ";
        int c1 = upper_bound(starts.begin(), starts.end(), i) - starts.begin();
        int c2 = upper_bound(ends.begin(), ends.end(), i) - ends.begin();
        arr[i] = c1-c2;
        if(i!=0) pArr[i] = pArr[i-1] + (ll)arr[i];
//        cout << arr[i]<<endl;
    }

    ll maxTime = LONG_LONG_MIN;
    ll maxTimeIndex = LONG_LONG_MAX;
    ll temp;
    for (int i = 0; i <= play_end - adv_length; ++i) {
        if(i==0) temp = pArr[i+adv_length];
        else temp = pArr[i+adv_length-1] - pArr[i-1];
        if(maxTime<temp){
            maxTimeIndex = i;
            maxTime = temp;
        }
    }
    for(auto x:test){
        cout<<secondsToDate(x-1)<<"- ";
        cout<<arr[x-1]<<'\n';
        cout<<secondsToDate(x)<<"- ";
        cout<<arr[x]<<'\n';
        cout<<secondsToDate(x+1)<<"- ";
        cout<<arr[x+1]<<'\n';
    }
    cout<<'\n';
    return secondsToDate(maxTimeIndex);
}

int main() {
    vector<string> answers;
    answers.push_back(solution("02:03:55", "00:14:15",
                               vector<string>{"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29",
                                              "01:30:59-01:53:29", "01:37:44-02:02:30"}));
    answers.push_back(solution("99:59:59", "25:00:00",
                               vector<string>{"69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59",
                                              "11:00:00-31:00:00"}));
    answers.push_back(solution("50:00:00", "50:00:00",
                               vector<string>{"15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45"}));
    for (const auto &answer:answers) {
        cout << answer << '\n';
    }
//    cout << dateToSeconds("02:03:55") << '\n';
//    cout<<secondsToDate(3216)<<'\n';

    return 0;
}