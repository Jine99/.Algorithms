#include<iostream>
#include<queue>

using namespace std;

int main(void) {
    queue<int> q;

    int a, b;
    cin >> a >> b;

    for (int i = 1; i <= a; i++) {
        q.push(i);
    }
    cout << "<";
    for (int i = 1;!q.empty();i++) {
        int temp = q.front();q.pop();
        if (i == b) {
            i = 0;
            q.empty() ? cout << temp : cout << temp << ", ";
            continue;
        }
        q.push(temp);
    }
    cout << ">";
}