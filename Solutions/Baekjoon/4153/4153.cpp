#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
    int a[3];

    while (cin >> a[0] >> a[1] >> a[2]) {
        if (a[0] + a[1] + a[2] == 0)break;
        sort(a, a + 3);
        a[2] * a[2] == a[0] * a[0] + a[1] * a[1] ? cout << "right" : cout << "wrong";
        cout << "\n";
    }
}