#include<iostream>
using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b = 1;
    cin >> a;
    a -= 1;
    while (a > 0) {
        a -= 6 * b;
        b++;
    }
    cout << b;
}