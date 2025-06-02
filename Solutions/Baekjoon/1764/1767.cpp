#include<iostream>
#include<set>

using namespace std;

set<string> S1, S2;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    string a;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a;
        S1.insert(a);
    }

    while (m--) {
        cin >> a;

        if (S1.insert(a).second) {

        }
        else {
            S2.insert(a);
        }
    }
    cout << S2.size() << "\n";
    for (auto i : S2) {
        cout << i << "\n";
    }
}