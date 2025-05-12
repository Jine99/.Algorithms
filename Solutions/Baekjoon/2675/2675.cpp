#include<iostream>
#include<string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a;
    string c;
    while (a--) {
        cin >> b;
        cin.ignore();
        cin >> c;
        for (int i = 0; i < c.size(); i++) {
            for (int k = 0; k < b; k++) {
                cout << c[i];
            }
        }
        cout << "\n";
    }
}