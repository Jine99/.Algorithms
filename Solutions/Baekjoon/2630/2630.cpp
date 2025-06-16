#include<iostream>

using namespace std;

int board[130][130];

int N, blue, white;

void cutting(int x, int y, int n) {

    bool cut = false;
    int color = board[x][y];

    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {

            if (board[i][j] != color) {
                cut = true;
                break;
            }
        }
    }

    if (cut) {
        cutting(x, y, n / 2);
        cutting(x + n / 2, y, n / 2);
        cutting(x, y + n / 2, n / 2);
        cutting(x + n / 2, y + n / 2, n / 2);
    }
    else {

        if (color == 1) {
            blue++;
        }
        else {
            white++;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    cutting(0, 0, N);

    cout << white << "\n" << blue;
}