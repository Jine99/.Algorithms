#include<iostream>

using namespace std;

int main(void) {
    int a;
    cin >> a;
    for (int i = 1; i <= a; i++) {
        for (int k = 0; k < i; k++) {
            cout << "*";
        }
        cout << "\n";
    }
}