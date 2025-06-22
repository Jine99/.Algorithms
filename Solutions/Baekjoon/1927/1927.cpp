#include<iostream>
#include<queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a;
    while (a--) {
        cin >> b;

        if (b != 0) {
            pq.push(b);
            continue;
        }

        if (pq.empty()) {
            cout << 0 << "\n";
        }
        else {
            cout << pq.top() << "\n";
            pq.pop();
        }
    }
}