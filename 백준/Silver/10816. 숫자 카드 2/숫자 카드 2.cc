#include<iostream>

using namespace std;

int arr[20000001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a;
    for (int i = 0; i < a; i++) {
        int c;
        cin >> c;
        arr[c + 10000000] += 1;
    }
    cin >> b;
    for (int i = 0; i < b; i++) {
        int d;
        cin >> d;
        cout << arr[d + 10000000] << " ";
    }

}