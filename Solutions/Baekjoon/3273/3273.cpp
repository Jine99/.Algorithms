#include<iostream>

using namespace std;

int arr[1000001]{ 0, };

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        int a;
        cin >> a;
        arr[a] = 1;

    }

    int target;
    cin >> target;

    int num = 0;
    for (int i = 1; i < 500000; i++) {

        if (arr[i] == 1 && arr[target - i] == 1) {
            arr[target - i] = 0;
            num++;
        }

    }
    cout << num;
}