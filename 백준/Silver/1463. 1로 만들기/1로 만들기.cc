#include<iostream>
#include<algorithm>

using namespace std;

int DP[1000001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b = 0;
    cin >> a;

    DP[1] = 0;

    for (int i = 2; i <= a; i++) {

        DP[i] = DP[i - 1] + 1;
        if (i % 3 == 0) {
            DP[i] = min(DP[i], DP[i / 3] + 1);
        }
        if (i % 2 == 0) {
            DP[i] = min(DP[i], DP[i / 2] + 1);
        }
    }
    cout << DP[a];
}