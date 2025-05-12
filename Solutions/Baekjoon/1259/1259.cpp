#include<iostream>

using namespace std;

int main(void) {
    while (true) {
        string a;
        cin >> a;
        if (a[0] == '0')break;
        bool b = true;
        for (int i = 0; i < a.size() / 2; i++) {
            if (a[i] != a[a.size() - 1 - i]) {
                b = false;
                break;
            }
        }
        b == 1 ? cout << "yes" : cout << "no";
        cout << "\n";
    }
}