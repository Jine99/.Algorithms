#include<iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        int a, b;
        cin >> a >> b;
        if (cin.eof()) break;
        cout << a + b << "\n";
    }
}
// int a, b;
// while (cin >> a >> b) {
//     cout << a + b << "\n";
// }
