#include<iostream>

using namespace std;

int arr[1001];

int tile(int n) {

    if (n == 1) return 1;
    if (n == 2) return 3;
    if (arr[n] != 0) return arr[n];
    return arr[n] = (tile(n - 1) + 2 * tile(n - 2)) % 10007;
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a;
    cin >> a;

    cout << tile(a);
}