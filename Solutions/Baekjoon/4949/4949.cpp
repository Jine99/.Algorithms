#include<iostream>
#include<stack>

using namespace std;

stack<char> stk;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        string command;
        getline(cin, command);
        if (command[0] == '.') {
            break;
        }
        for (int i = 0; i < command.length(); i++) {
            if (command[i] == '(' || command[i] == '[') stk.push(command[i]);
            if (command[i] == ')') stk.empty() ? stk.push(command[i]) : stk.top() == '(' ? stk.pop() : stk.push(command[i]);
            if (command[i] == ']') stk.empty() ? stk.push(command[i]) : stk.top() == '[' ? stk.pop() : stk.push(command[i]);
        }
        stk.empty() ? cout << "yes\n" : cout << "no\n";

        while (!stk.empty())stk.pop();
    }
}