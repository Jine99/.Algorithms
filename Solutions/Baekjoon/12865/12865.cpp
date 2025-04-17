#include<iostream>

using namespace std;

int main(void) {

    int n;
    int k;
    cin >> n >> k;

    int w[101]{ 0, };
    int v[101]{ 0, };
    int dp[101][100001]{ 0, };

    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    for (int i = 1; i <= k; i++) {

        for (int q = 1; q <= n; q++) {

        }
    }

    cout << dp[n][k];
}