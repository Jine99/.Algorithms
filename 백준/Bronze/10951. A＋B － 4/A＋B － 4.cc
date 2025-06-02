#include<iostream>

using namespace std;

int main(void) {
    while (true) {
        int b, c;
        cin >> b >> c;
        if (cin.eof()) break;
        cout << b + c << "\n";
    }
}