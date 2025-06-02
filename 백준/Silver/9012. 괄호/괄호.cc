#include<iostream>
#include<stack>

using namespace std;

int main(void) {

    int a;
    cin >> a;

    while (a--) {
        stack<char> stk;

        string st;
        cin >> st;
        for (int i = 0; i < st.length(); i++) {

            if (stk.empty()) { stk.push(st[i]);continue; }

            if (stk.top() == '(' && st[i] == ')') {

                stk.pop();
            }
            else {
                stk.push(st[i]);
            }
        }

        stk.empty() ? cout << "YES" : cout << "NO";
        cout << endl;
    }
}
