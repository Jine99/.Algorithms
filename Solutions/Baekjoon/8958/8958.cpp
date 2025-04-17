#include<iostream>
#include<string>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;

    cin >> a;

    while (a--) {
        int num = 0;
        int plus = 1;
        string s;
        cin >> s;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'X') {
                plus = 1;
                continue;
            }
            else {
                num += plus;
                plus++;
            }
        }
        cout << num << "\n";
    }

}

