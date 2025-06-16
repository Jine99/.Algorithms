#include<iostream>

using namespace std;

bool board[51][51];
bool vis[51][51];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int m, n, k;

void BFS(int x, int y) {

    vis[y][x] = 1;

    for (int i = 0; i < 4; i++) {

        int ny = y + dy[i];
        int nx = x + dx[i];
        if (nx < 0 || 0 > ny && nx >= m || n <= ny) continue;
        if (board[ny][nx] == 0 || vis[ny][nx] == 1)continue;
        BFS(nx, ny);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int num = 0;

        cin >> m >> n >> k;

        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (board[y][x] == 1 && vis[y][x] == 0) {
                    num++;
                    BFS(x, y);
                }
            }
        }
        cout << num << "\n";

        fill_n(board[0], 51 * 51, 0);
        fill_n(vis[0], 51 * 51, 0);
    }
}