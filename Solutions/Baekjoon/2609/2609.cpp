#include<iostream>

using namespace std;

int main(void) {
    int a, b, c = 0, d = 0;

    cin >> a >> b;
    c = a;
    d = b;
    while (true) {
        int e = c % d;
        if (e == 0) {
            break;
        }
        c = d;
        d = e;
    }
    cout << d << "\n" << a * b / d;
}

// int i = 0;
// for (i = a; i >= 1; i--) {
//     if (a % i == 0 && b % i == 0)break;
// }