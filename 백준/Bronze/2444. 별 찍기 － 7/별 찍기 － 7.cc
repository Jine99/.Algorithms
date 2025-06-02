#include<iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;
    cin >> a;

    int run = a;
    int c = a - 1;

    for (int i = 0; i < a * 2 - 1; i++) {

        for (int k = 0; k < run; k++) {

            if (k < c) {
                cout << " ";
            }
            else {
                cout << "*";
            }
        }
        cout << "\n";
        if (i < a - 1) {
            c -= 1;
            run += 1;
        }
        else {
            c += 1;
            run -= 1;
        }
    }
}