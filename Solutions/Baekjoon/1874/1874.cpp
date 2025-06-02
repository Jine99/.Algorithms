#include <bits/stdc++.h>

using namespace std;

stack<int> stk;

int main(void) {

    int a;
    int b = 1;
    cin >> a;
    string std;
    while (a--) {
        int c;
        cin >> c;
        while (b <= c) {
            stk.push(b++);
            std += "+\n";
        }
        if (stk.top() == c) {
            stk.pop();
            std += "-\n";
        }
    }
    if (!stk.empty()) {
        std = "NO";
    }
    cout << std;
}