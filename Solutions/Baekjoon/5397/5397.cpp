#include <bits/stdc++.h>

using namespace std;

list<char> dat(1000000);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    list<char>::iterator cursor = dat.begin();
    int a;
    cin >> a;
    while (a--) {
        string b;
        cin >> b;
        for (int i = 0; i < b.length(); i++) {
            char aaa = b[i];
            cout << b[i];
            if (b[i] == '<') {
                if (dat.begin() != cursor) cursor--;
            }
            else if (b[i] == '>') {
                if (dat.end() != cursor) cursor++;
            }
            else if (b[i] == '-') {
                if (dat.begin() != cursor)
                    dat.erase(--cursor);
            }
            else {
                dat.insert(cursor, b[i]);
                cursor++;
                cout << b[i];
            }
        }

        cursor = dat.begin();
        cout << "\n";
    }
}