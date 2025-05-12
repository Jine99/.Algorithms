#include<iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;
    cin >> a;
    while (a--) {
        int b, c;
        cin >> b >> c;
        cout << b + c << "\n";
    }
}