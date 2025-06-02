#include<iostream>

using namespace std;

int main() {
    //for문 2개로 해결해보기(연습)
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;
    cin >> a;

    int run = a;
    int b = a - 1;

    for (int i = 0; i < a * 2 - 1; i++) {

        for (int k = 0; k < run; k++) {

            if (k < b) {
                cout << " ";
            }
            else {
                cout << "*";
            }
        }
        cout << "\n";
        if (i < a - 1) {
            b -= 1;
            run += 1;
        }
        else {
            b += 1;
            run -= 1;
        }
    }
}