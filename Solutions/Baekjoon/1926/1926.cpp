#include<iostream>
#include<queue>

using namespace std;

int board[502][502];
bool vis[502][502];
int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };

queue<pair<int, int>> q;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num = 0;
    int maxsize = 0;
    int a = 0;

    int boardy, boardx;

    cin >> boardy;
    cin >> boardx;

    for (int i = 0; i < boardy; i++) {
        for (int k = 0; k < boardx; k++) {
            int a;
            cin >> a;
            board[i][k] = a;
        }
    }
    for (int i = 0; i < boardy; i++) {
        for (int k = 0; k < boardx; k++) {
            if (board[i][k] != 0 && vis[i][k] != 1) {
                q.push({ i,k });
                num++;
            }
            while (!q.empty()) {
                a++;
                pair<int, int> cur = q.front(); q.pop();
                vis[cur.first][cur.second] = 1;
                for (int dir = 0; dir < 4;dir++) {
                    int y = cur.first + dy[dir];
                    int x = cur.second + dx[dir];
                    if (y < 0 || y >= boardy || x < 0 || x >= boardx) continue;
                    if (vis[y][x] || board[y][x] != 1) continue;
                    vis[y][x] = 1;
                    q.push({ y,x });
                }
                if (q.empty()) maxsize < a ? maxsize = a : maxsize = maxsize, a = 0;
            }
        }
    }
    cout << num << "\n" << maxsize;
}