#include<iostream>
#include<queue>

using namespace std;

queue<int> q[1002];
bool vis[1002];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    queue<int> q2;

    int n, m, link = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;
        q[u].push(v);
        q[v].push(u);
    }

    for (int i = 1; i <= n; i++) {
        if (q[i].empty()) {
            if (vis[i] == 0) {
                vis[i] = 1;
                link++;
            }
            continue;
        }
        q2 = q[i];
        while (!q2.empty()) {
            int e = q2.front();q2.pop();
            if (vis[e] == 1)continue;
            vis[e] = 1;
            while (!q[e].empty()) {
                q2.push(q[e].front());q[e].pop();
            }
        }
        link++;
    }
    cout << link;
}
