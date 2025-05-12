#include<iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int c = a - b;
    int d = 1, e = 1, f = 1;
    for (int i = 1; i <= a; i++) {
        d *= i;
    }
    for (int i = 1; i <= b; i++) {
        e *= i;
    }
    for (int i = 1; i <= c; i++) {
        f *= i;
    }
    cout << d / (e * f);
}