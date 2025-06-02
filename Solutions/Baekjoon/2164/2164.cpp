#include<queue>
#include<iostream>

using namespace std;

queue<int> q;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    bool odd = true;
    for (int i = 1; i <= n; i++) q.push(i);
    while (true) {
        if (q.size() == 1) break;
        else  if (odd = !odd) q.push(q.front());
        q.pop();
    }
    cout << q.front();
}