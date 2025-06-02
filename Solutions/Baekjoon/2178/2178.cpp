#include<iostream>
#include<queue>

using namespace std;

const int  Max = 102;

string miro[Max];

int board[Max][Max];

int x[] = { 1,0,-1,0 };
int y[] = { 0,1,0,-1 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q;

    int num = 0;

    int n, m;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> miro[i];
    }

    Q.push({ 0,0 });
    board[0][0] = 0;
    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for (int i = 0; i < 4; i++) {
            int dy = cur.first + y[i];
            int dx = cur.second + x[i];
            if (dy < 0 || dy >= n || dx < 0 || dx >= m) continue;
            if (board[dy][dx] >= 0 || miro[dy][dx] != '1') continue;
            board[dy][dx] = board[cur.first][cur.second] += 1;
            Q.push({ dy,dx });
        }
        if (cur.first == n && cur.second == m) num = board[n - 1][m - 1];
    }
    cout << num;
}
