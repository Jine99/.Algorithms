#include<iostream>
#include<queue>

using namespace std;

queue<int> q[101];
bool vis[101];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    queue<int> a;

    int b, c, count = 0;
    cin >> b >> c;
    for (int i = 0; i < c; i++) {
        int d, e;
        cin >> d >> e;
        q[d].push(e);
        q[e].push(d);
    }

    a = q[1];
    vis[1]=1;

    while (!a.empty()) {
        int e = a.front();a.pop();
        if (vis[e] == 1)continue;
            vis[e] = 1;
            count++;
        while (!q[e].empty()) {
            a.push(q[e].front());q[e].pop();
        }
    }
    cout<<count;
}  