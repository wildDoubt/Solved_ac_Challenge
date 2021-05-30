#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using p = pair<int, int>;

const int INF = 0x66554433;
int arr[100][100];
inline void quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void construct(int a){
    int num = 1;
    if(a==3){
        cout<<"2 9 7\n";
        cout<<"4 6 3\n";
        cout<<"1 8 5\n";
        return;
    }
    for(int i = 0;i<a;i++){
        for(int j = 0;j<a;j+=2){
            arr[i][j] = num;
            num++;
        }
    }
    for(int i = 0;i<a;i++){
        for(int j = 1;j<a;j+=2){
            arr[i][j] = num;
            num++;
        }
    }
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < a; ++j) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    quick_IO();
    int t;
    int i, j, k;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==2){
            cout<<-1<<'\n';
            continue;
        }
        construct(n);
    }
    return 0;
}