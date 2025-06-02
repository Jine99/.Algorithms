#include <iostream>
using namespace std;
int n[10]{ 0, };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C;
    cin >> A >> B >> C;

    int b = A * B * C;

    while (b > 0) {

        n[b % 10] += 1;
        b = b / 10;
    }

    for (int i = 0; i < 10; i++) {

        cout << n[i] << "\n";
    }
}