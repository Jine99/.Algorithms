#include <bits/stdc++.h>

using namespace std;

stack<int> stk;

int main(void) {

    int a;
    cin >> a;
    while (a--) {
        string b;
        cin >> b;
        if (b == "push") {
            int c;
            cin >> c;
            stk.push(c);
        }
        else if (b == "pop") {
            int d = -1;
            if (!stk.empty()) {
                d = stk.top();
                stk.pop();
            }
            cout << d << "\n";
        }
        else if (b == "size") {
            cout << stk.size() << "\n";
        }
        else if (b == "empty") {
            stk.empty() ? cout << 1 << "\n" : cout << 0 << "\n";
        }
        else if (b == "top") {
            stk.empty() ? cout << "-1\n" : cout << stk.top() << "\n";
        }
    }

}

