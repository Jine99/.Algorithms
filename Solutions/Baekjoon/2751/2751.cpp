#include<iostream>
#include<algorithm>

using namespace std;

int arr[1000000];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + a);

    for (int i = 0; i < a; i++) {
        cout << arr[i] << "\n";
    }
}