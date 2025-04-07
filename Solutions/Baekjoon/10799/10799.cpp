#include<iostream>
#include<stack>

using namespace std;

stack<char> stk;

int main(void) {
    int num;
    int stknum = 0;
    string command;
    cin >> command;

    for (int i = 0; i < command.length(); i++) {
        stk.push(command[i]);
        if (stk.top() == '(' && command[i + 1] == ')') {
            stk.pop();
            i++;
            num += stknum;
        }
        else if (stk.top() == '(') {
            stknum++;
        }
        else if (stk.top() == ')') {
            stknum--;
            num++;
        }
    }

    cout << num;
}