#include <bits/stdc++.h>
using namespace std;

stack<int> stk;

int main(void) {
    int a;
    cin >> a;
    while (a--) {
        int b;
        cin >> b;
        if (b == 0) {
            stk.pop();
        }
        else {
            stk.push(b);
        }
    }

    int c = 0;
    while (!stk.empty()) {
        c += stk.top();
        stk.pop();
    }
    cout << c;
}
