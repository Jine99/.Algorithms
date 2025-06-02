#include<iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0)break;
        cout << a + b << "\n";
    }
}