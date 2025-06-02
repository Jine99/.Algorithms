#include<iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a = 0;
    int b = 0;
    for (int i = 1; i <= 9; i++) {
        int c;
        cin >> c;
        if (a <= c) {
            a = c;
            b = i;
        }
    }
    cout << a << "\n" << b;
}