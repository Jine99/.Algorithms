#include<iostream>
#include<unordered_map>

using namespace std;

unordered_map<int, int> dic;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, card;
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> card;
        dic[card] += 1;
    }
    cin >> b;
    for (int i = 0; i < b; i++) {
        cin >> card;
        cout << dic[card] << " ";
    }
}