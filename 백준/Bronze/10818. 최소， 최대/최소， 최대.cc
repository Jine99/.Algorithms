#include<iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c = 1000000, d = -1000000;
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> b;
        if (d <= b) {
            d = b;
        }
        if (c >= b) {
            c = b;
        }
    }
    cout << c << " " << d;
}