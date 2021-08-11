#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

inline void Quick_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

class Deque {
private:
    int *arr;
    int head;
    int tail;
    int length;
public:
    Deque(int n) {
        arr = new int[n];
        head = 0;
        tail = 1;
        length = n + 1;
    }

    int pop_back() {
        int ret = back();
        tail = (tail - 1 + length) % length;
        return ret;
    }

    int pop_front() {
        int ret = front();
        head = (head + 1) % length;
        return ret;
    }

    void push_back(int x) {
        arr[tail] = x;
        tail = (tail + 1) % length;
    }

    void push_front(int x) {
        arr[head] = x;
        head = (head - 1 + length) % length;
    }

    bool empty() {
        return !size();
    }

    int back() {
        return arr[(tail - 1 + length) % length];
    }

    int front() {
        return arr[(head + 1) % length];
    }

    int size() {
        return (tail - head + length) % length - 1;
    }
};

int main() {
    Quick_IO();
    int Q, num;
    cin >> Q;
    string q;
    Deque d(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> q;
        if (cin.peek() == ' ') {
            cin >> num;
            if (q == "push_back") {
                d.push_back(num);
            } else {
                d.push_front(num);
            }
        } else {
            if (q == "pop_front") {
                if (d.empty()) cout << "-1\n";
                else cout << d.pop_front() << '\n';
            } else if (q == "pop_back") {
                if (d.empty()) cout << "-1\n";
                else cout << d.pop_back() << '\n';
            } else if (q == "size") {
                cout << d.size() << '\n';
            } else if (q == "empty") {
                cout << d.empty() << '\n';
            } else if (q == "front") {
                if (d.empty()) cout << "-1\n";
                else cout << d.front() << '\n';
            } else if (q == "back") {
                if (d.empty()) cout << "-1\n";
                else cout << d.back() << '\n';
            }
        }
    }
    return 0;
}