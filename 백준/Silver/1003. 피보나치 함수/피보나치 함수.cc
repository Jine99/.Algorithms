#include<iostream>

using namespace std;

int a, b;

pair<int, int> c[40];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int d, e;
    cin >> d;
    c[0].first = 1;c[0].second = 0;
    c[1].first = 0; c[1].second = 1;

    while (d--) {

        cin >> e;
        if (e > 1) {
            for (int i = 2; i <= e; i++) {
                c[i].first = c[i - 1].first + c[i - 2].first;
                c[i].second = c[i - 1].second + c[i - 2].second;
            }
        }
        cout << c[e].first << " " << c[e].second << "\n";
    }
}