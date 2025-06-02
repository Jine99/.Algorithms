#include<iostream>
#include<cmath>

using namespace std;
int a[6]{ 0, };
int main(void) {
    int b;
    cin >> b;
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }
    int c, d;
    cin >> c >> d;
    int f = 0, g = 0;
    for (int i = 0; i < 6; i++) {
        f += ceil(a[i] / (double)c);
    }
    cout << f << "\n";
    cout << b / d << " " << b % d;
}