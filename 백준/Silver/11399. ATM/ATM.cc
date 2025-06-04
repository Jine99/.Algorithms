#include<iostream>
#include<algorithm>

using namespace std;

int arr[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b = 0, c = 0;
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> arr[i];
    }

    sort (arr, arr + a);

    for (int i = 0; i < a; i++) {
        b = arr[i] + b;
        c += b;
    }
    cout << c;
}