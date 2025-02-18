#include<iostream>
#include<deque>

using namespace std;

deque<int> de;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num;
    cin >> num;
    while (num--) {
        string command;
        cin >> command;
        int a = 0;

        if (command == "push_front") {
            cin >> a;
            de.push_front(a);
            continue;
        }
        else if (command == "push_back") {
            cin >> a;
            de.push_back(a);
            continue;
        }
        else if (command == "pop_front") {
            if (de.empty()) {
                cout << -1;
            }
            else {
                cout << de.front();
                de.pop_front();
            }
        }
        else if (command == "pop_back") {
            if (de.empty()) {
                cout << -1;
            }
            else {
                cout << de.back();
                de.pop_back();
            }
        }
        else if (command == "size") {
            cout << de.size();
        }
        else if (command == "empty") {
            de.empty() ? cout << 1 : cout << 0;
        }
        else if (command == "front") {
            de.empty() ? cout << -1 : cout << de.front();
        }
        else if (command == "back") {
            de.empty() ? cout << -1 : cout << de.back();
        }
        cout << "\n";

    }

}