#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

set<string> inputset, outset;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c = 0;
    string aa, bb;

    cin >> a >> b;
    for (int i = 0; i < a; i++) {
        cin >> aa;
        inputset.insert(aa);
    }

    while (b--) {
        cin >> bb;

        if (inputset.insert(bb).second) {

        }
        else {
            outset.insert(bb);
        }
    }
    cout << outset.size() << "\n";
    for (auto i : outset) {
        cout << i << "\n";
    }
}