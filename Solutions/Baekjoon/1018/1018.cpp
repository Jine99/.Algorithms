#include<iostream>
#include<algorithm>

using namespace std;

string bord[51];

int check(char c, int x, int y) {
    int num = 0;
    for (int i = x; i < x + 8; i++) {

        for (int j = y; j < y + 8; j++) {

            if ((i + j) % 2 == 0) {
                if (bord[i][j] != c) {
                    num++;
                }
            }
            else {
                if (bord[i][j] == c) {
                    num++;
                }
            }
        }

    }
    return num;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, minnum = 64;
    cin >> a >> b;

    for (int i = 0; i < a; i++) {
        cin >> bord[i];
    }

    for (int i = 0; i + 8 <= a; i++) {

        for (int q = 0; q + 8 <= b; q++) {

            int c = min(check('B', i, q), check('W', i, q));

            if (minnum > c) minnum = c;
        }
    }
    cout << minnum;
}