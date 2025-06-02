#include<queue>
#include<iostream>

using namespace std;

queue<int> q1, q2;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin >> a;


    for (int i = 1; i <= a; i++) {
        q1.push(i);
    }
    while (true) {

        if (q1.size() == 1) {
            break;
        }
        else {
            q1.pop();
        }
        q1.push(q1.front());
        if (q1.size() == 1) {
            break;
        }
        else {
            q1.pop();
        }

    }
    cout << q1.front();
}
