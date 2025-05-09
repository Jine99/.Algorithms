#include<iostream>
#include <iomanip> 

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long double a, b = 0, c = 0;
    cin >> a;

    for (int i = 0; i < a; i++) {
        long double d;
        cin >> d;
        b += d;
        if (c < d) {
            c = d;
        }
    }
    cout << fixed << b / a / c * 100.0;
}