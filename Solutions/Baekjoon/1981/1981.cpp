// #include<iostream>
// #include<queue>

//vis[x][y] = min(vis[x][y], max(vis[prevx][prevy], abs(arr[prevx][prevy] - arr[x][y])));

// using namespace std;

// static int size(int a, int b, int c) {
//     return abs(b - a) < abs(a - c) ? abs(b - a) : abs(a - c);
// }

// int board[100][100];
// bool vis[100][100];
// int x[4]{ 1,0,-1,0 };
// int y[4]{ 0,1,0,-1 };

// int main(void) {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     queue<pair<int, int>> road;
//     queue<pair<int, int>> Q;

//     vis[0][0] = 1;
//     Q.push({ 0,0 });

//     int boardSize;
//     cin >> boardSize;

//     for (int y = 0; y < boardSize; y++) {
//         for (int x = 0; x < boardSize; x++) {
//             int input;
//             cin >> input;
//             board[y][x] = input;
//         }
//     }

//     int small = board[0][0];
//     int big = board[boardSize - 1][boardSize - 1];

//     if (small > big) {
//         int tmep = small;
//         small = big;
//         big = tmep;
//     }

//     while (!Q.empty()) {
//         pair<int, int> cur = Q.front();
//         if (cur.first == boardSize - 1 && cur.second == boardSize - 1) break;
//         Q.pop();
//         for (int dir = 0; dir < 4; dir++) {
//             int ny = cur.first + y[dir];
//             int nx = cur.second + x[dir];
//             if (nx < 0 || nx >= boardSize || ny < 0 || ny >= boardSize) continue;
//             if (vis[ny][nx] == 1) continue;
//             if (big >= board[ny][nx] && small <= board[ny][nx]) {
//                 vis[ny][nx] = 1;
//                 Q.push({ ny,nx });
//                 continue;
//             }
//             else if (road.empty()) {
//                 road.push({ ny,nx });
//                 continue;
//             }
//             int boardnum = size(board[ny][nx], big, small);
//             int numsize = size(board[road.front().first][road.front().second], big, small);

//             if (boardnum < numsize) {
//                 road.pop();
//                 road.push({ ny,nx });
//                 continue;
//             }
//             else if (boardnum == numsize) {
//                 road.push({ ny,nx });
//             }

//         }
//         if (Q.empty() && !road.empty()) {
//             if (board[road.front().first][road.front().second] > big) {
//                 big = board[road.front().first][road.front().second];
//             }
//             else if (board[road.front().first][road.front().second] < small) {
//                 small = board[road.front().first][road.front().second];
//             }
//             vis[road.front().first][road.front().second] = 1;
//             Q.push(road.front());
//             road.pop();
//         }
//     }
//     cout << big - small;
// }
// // 실패 다시 풀어보자