#include<iostream>
#include<stack>

using namespace std;

stack<char>stk;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string command;
    cin >> command;

    int temp = 1;
    int num = 0;
    int answer = 0;

    for (int i = 0; i < command.length(); i++) {

        if (command[i] == '(') {
            stk.push(command[i]);
            temp *= 2;
            num = temp;

        }
        else if (command[i] == '[') {
            stk.push(command[i]);
            temp *= 3;
            num = temp;
        }

        if (command[i] == ')') {
            if (stk.empty()) {
                answer = 0;
                break;
            }

            if (stk.top() == '[') {
                answer = 0;
                break;
            }

            if (stk.top() == '(') {
                if (command.length() <= i + 1 || command[i + 1] == '[' || command[i + 1] == '(') {
                    answer += num;
                }
                stk.pop();
                temp /= 2;
                continue;
            }

        }
        else if (command[i] == ']') {
            if (stk.empty()) {
                answer = 0;
                break;
            }
            if (stk.top() == '(') {
                answer = 0;
                break;
            }

            if (stk.top() == '[') {
                if (command.length() <= i + 1 || command[i + 1] == '[' || command[i + 1] == '(') {
                    answer += num;
                }
                stk.pop();
                temp /= 3;
                continue;
            }
        }
    }
    if (!stk.empty()) answer = 0;
    cout << answer;
}
