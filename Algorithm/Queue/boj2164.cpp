#include <iostream>
#include <deque>

using namespace std;

int main() {
    int N;
    cin >> N;
    deque<int> cards(N);
    for (int i = 0; i < N; ++i) {
        cards[i] = i;
    }

    bool discard = true;
    while (cards.size() != 1) {
        if (discard) {
            cards.pop_front();
        } else {
            cards.push_back(cards.front());
            cards.pop_front();
        }
        discard=!discard;
    }
    cout<<cards.front()+1<<'\n';
    return 0;
}