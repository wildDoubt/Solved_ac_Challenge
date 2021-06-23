#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int main() {
    stack<char> stack;
    map<char, int> operator_priority;

    string input;
    cin >> input;

    operator_priority['/'] = 2;
    operator_priority['*'] = 2;
    operator_priority['+'] = 1;
    operator_priority['-'] = 1;

    for (int i = 0; i < (int) input.size(); ++i) {
        char curr_op = input[i];

        if (curr_op >= 'A' && curr_op <= 'Z') {
            cout << curr_op;
            continue;
        }
        if (curr_op == ')') {
            while (stack.top() != '(') {
                cout << stack.top();
                stack.pop();
            }
            stack.pop();
            continue;
        }
        if (stack.empty() ||
            curr_op == '(' ||
            operator_priority[curr_op] > operator_priority[stack.top()]) {
            stack.push(curr_op);
        } else {
            while (!stack.empty() &&
                   operator_priority[stack.top()] >= operator_priority[curr_op]) {
                cout << stack.top();
                stack.pop();
            }
            stack.push(curr_op);
        }
    }

    while (!stack.empty()) {
        cout << stack.top();
        stack.pop();
    }

    return 0;
}