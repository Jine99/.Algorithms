#include<iostream>

using namespace std;

int arr[1001];

int main(void) {

    arr[1] = 1;
    arr[2] = 2;

    int a;
    cin >> a;

    for (int i = 3; i <= a; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
    }

    cout << arr[a];
}