#include <bits/stdc++.h>

using namespace std;

stack<pair<int, int>> stk;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a;
    cin >> a;
    int c = 0;
    while (a--) {
        int b;
        cin >> b;
        c++;
        while (!stk.empty() && stk.top().first < b) stk.pop();
        if (stk.empty()) cout << "0 ";
        else cout << stk.top().second << " ";
        stk.push({ b,c });
    }
}