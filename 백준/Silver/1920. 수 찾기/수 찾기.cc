#include<iostream>
#include<map>

using namespace std;

map<int, int> intmap;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a;

    for (int i = 0; i < a; i++) {
        int c;
        cin >> c;
        intmap[c] = c;
    }
    cin >> b;
    for (int i = 0; i < b; i++) {
        int d;
        cin >> d;
        intmap.find(d) != intmap.end() ? cout << 1 : cout << 0;
        cout << "\n";
    }
}