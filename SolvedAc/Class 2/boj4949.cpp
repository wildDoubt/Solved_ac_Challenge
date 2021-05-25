#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
    while (true) {
        string s;
        getline(cin, s);
        if (s == ".") break;
        stack<char> st;
        for (auto c:s) {
            if (c == '(' || c == '[') st.push(c);
            if (c == ')' || c == ']') {
                if (st.empty()) {
                    st.push(1);
                    break;
                } else {
                    if (c == ')') {
                        if (st.top() == '(') {
                            st.pop();
                        }else{
                            break;
                        }
                    }
                    if (c == ']') {
                        if (st.top() == '[') {
                            st.pop();
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        if (st.empty()) cout << "yes\n";
        else cout << "no\n";
    }


    return 0;
}