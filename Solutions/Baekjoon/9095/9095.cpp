#include<iostream>

using namespace std;

int DP[11];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    DP[0] = 1;
    DP[1] = 2;
    DP[2] = 4;
    for (int i = 3; i < 11; i++) {
        DP[i] = DP[i - 3] + DP[i - 2] + DP[i - 1];
    }

    int a, b;
    cin >> a;

    while (a--) {
        cin >> b;
        cout << DP[b - 1] << "\n";
    }

}