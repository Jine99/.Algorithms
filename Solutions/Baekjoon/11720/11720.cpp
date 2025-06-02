#include<iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;
    string b;

    cin >> a;
    cin >> b;

    int c = 0;

    for (int i = 0; i < a; i++) {
        c += b[i] - '0';
    }

    cout << c;
}