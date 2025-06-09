#include<iostream>

using namespace std;

long long DP[101];

long long triangle(int n) {

    if (n == 1) return 1;
    if (n == 2) return 1;
    if (n == 3) return 1;
    if (DP[n] != 0) return DP[n];
    return DP[n] = triangle(n - 2) + triangle(n - 3);
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;

    cin >> a;

    while (a--) {
        cin >> b;
        cout << triangle(b) << "\n";
    }
}