#include<iostream>
#include<string>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    string str;

    cin >> N;
    while (cin >> str) {

        int num = 0;
        int plus = 0;

        for (int i = 0; i < str.length(); i++) {
            num += plus = str[i] - 79 ? 0 : ++plus;
        }
        cout << num << "\n";
    }
}