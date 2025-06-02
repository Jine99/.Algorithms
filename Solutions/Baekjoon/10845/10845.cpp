#include<queue>
#include<iostream>

using namespace std;

queue<int> q;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin >> a;
    while (a--) {
        string b;
        cin >> b;
        if (b == "push") {
            int c;
            cin >> c;
            q.push(c);
            continue;
        }
        else if (b == "pop") {
            if (q.empty()) {
                cout << -1;
            }
            else {
                cout << q.front();
                q.pop();
            }
        }
        else if (b == "size") {
            cout << q.size();
        }
        else if (b == "empty") {
            cout << q.empty();
        }
        else if (b == "front") {
            cout << (q.empty() ? -1 : q.front());
        }
        else if (b == "back") {
            cout << (q.empty() ? -1 : q.back());
        }
        cout << "\n";
    }

}