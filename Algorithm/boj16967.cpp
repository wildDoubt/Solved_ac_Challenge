#include <iostream>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    Quick_IO();
    int H, W, X, Y;

    cin >> H >> W >> X >> Y;

    int arr[H+X][W+Y];

    for (int i = 0; i < H + X; ++i) {
        for (int j = 0; j < W + Y; ++j) {
            cin>>arr[i][j];
        }
    }
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if(i>=X&&j>=Y){
                arr[i][j] -= arr[i-X][j-Y];
            }
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }

    return 0;
}