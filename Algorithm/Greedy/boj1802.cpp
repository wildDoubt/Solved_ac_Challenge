#include <iostream>
#include <algorithm>

using namespace std;

bool calc(int start, int end, string& info){
    if(end <= start) return true;

    int mid = (start + end) / 2;
    int left = start;
    int right = end;

    while(left<right){
        if(info[left++]==info[right--]){
            return false;
        }
    }

    int leftResult = calc(start, mid-1, info);
    int rightResult = calc(mid+1, end, info);
    return leftResult && rightResult;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string info;
        cin>>info;
        int length = (int)info.length();
        bool possible = calc(0, length-1, info);
        if(possible) cout<<"YES";
        else cout<<"NO";
        cout<<'\n';
    }

    return 0;
}