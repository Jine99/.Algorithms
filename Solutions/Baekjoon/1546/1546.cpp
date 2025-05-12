#include<iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    double a, b = 0, c = 0;
    cin >> a;

    for (int i = 0; i < a; i++) {
        double d;
        cin >> d;
        b += d;
        if (c < d) {
            c = d;
        }
    }
    cout << b / a / c * 100.0;
}