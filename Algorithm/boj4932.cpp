#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t, index = 0;
    cin >> t;
    while (index++<t) {
        int N;
        cin>>N;
        int arr[N][N];
        string answer = "YES";
        for (int i = 0; i < N; ++i) {
            cin>>arr[0][i];
        }
        for (int i = 1; i < N; ++i) {
            cin>>arr[i][0];
            int prev = arr[i][0] - arr[0][0];
            for (int j = 1; j < N; ++j) {
                cin>>arr[i][j];
                if(prev!=arr[i][j] - arr[0][j]){
                    answer="NO";
                }
            }
        }
        cout<<index<<". "<<answer<<'\n';
    }

    return 0;
}