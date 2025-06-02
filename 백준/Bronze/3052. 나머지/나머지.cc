#include<iostream>

using namespace std;

int arr[42];
int main(void) {
    int a = 0;
    for (int i = 0; i < 10; i++) {
        int b;
        cin >> b;
        b = b % 42;
        if (arr[b] == 0) {
            arr[b] = 1;
            a++;
        }
    }
    cout << a;
}