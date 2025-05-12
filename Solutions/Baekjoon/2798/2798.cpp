#include<iostream>

using namespace std;
int arr[100]{ 0, };
int main(void) {
    int a, b, c = 0;
    cin >> a >> b;
    for (int i = 0; i < a; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < a - 2; i++) {
        if (b < arr[i])continue;
        for (int k = i + 1; k < a - 1; k++) {
            if (b < arr[k])continue;
            for (int j = k + 1; j < a; j++) {
                if (b < arr[j])continue;
                int d = arr[i] + arr[k] + arr[j];
                if (d > c && d <= b) {
                    c = d;
                }
            }
        }
    }
    cout << c;
}