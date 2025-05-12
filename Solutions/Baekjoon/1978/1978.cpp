#include<iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b = 0;
    cin >> a;

    while (a--) {
        int c;
        bool d = true;
        cin >> c;
        if (c == 1) continue;

        for (int i = 2; i < c; i++) {

            if (c % i < 1) {
                d = false;
                continue;
            }
        }
        if (d == true) {
            b++;
        }
    }
    cout << b;
}