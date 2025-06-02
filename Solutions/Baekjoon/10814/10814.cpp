#include<iostream>
#include<algorithm>

using namespace std;

pair<int, string> b[100000];

bool comp(pair<int, string> p1, pair<int, string> p2) {
    return p1.first < p2.first;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a;
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> b[i].first >> b[i].second;
    }

    stable_sort(b, b + a, comp);

    for (int i = 0; i < a; i++) {
        cout << b[i].first << " " << b[i].second << "\n";
    }
}