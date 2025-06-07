#include<iostream>

using namespace std;

int arr[100002];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, num, d, e;

    cin >> a >> b;

    for (int i = 1; i <= a; i++) {
        cin >> num;
        arr[i] = arr[i - 1] + num;

    }

    while (b--) {
        cin >> d >> e;

        cout << arr[e] - arr[d - 1] << "\n";
    }

}