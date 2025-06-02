
#include <bits/stdc++.h>

using namespace std;

int main(void) {

    int ferq[26] = { 0, };
    string aa;
    cin >> aa;

    for (auto c : aa) ferq[c - 'a']++;
    for (int i = 0; i < 26; i++) cout << ferq[i] << ' ';

    //     for (char a = 'a'; a <= 'z';a++) {
    //         int count = 0;
    //         for (char b : aa) {
    //             if (b == a) count++;
    //         }
    //         cout << count << ' ';
    //     }
}