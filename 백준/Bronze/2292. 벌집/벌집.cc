#include<iostream>
using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;
    int b = 1;
    int c = 1;
    cin >> a;
    if (a >= 1) {

        for (int i = 0; i < a; i++) {

            b = b + (6 * i);
            if (b >= a) {
                c = i + 1;
                break;
            }

        }
    }
    cout << c;
}