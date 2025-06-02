#include<iostream>
#include<cmath>

using namespace std;
long long a[6]{ 0, };
int main(void) {
    long long b;
    cin >> b;
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }
    long long c, d;
    cin >> c >> d;
    long long f = 0, g = 0;
    for (int i = 0; i < 6; i++) {
        f += ceil(a[i] / (double)c);
    }
    cout << f << "\n";
    cout << b / d << " " << b % d;
}