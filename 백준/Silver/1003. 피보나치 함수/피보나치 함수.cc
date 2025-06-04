    #include<iostream>

using namespace std;

int arr[42];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    arr[0] = 1;arr[1] = 0;
    for (int i = 2; i < 42; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    int a, b;
    cin >> a;

    while (a--) {
        cin >> b;
        cout << arr[b] << " " << arr[b + 1] << "\n";
    }
}