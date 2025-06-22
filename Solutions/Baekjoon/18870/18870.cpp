#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;
    cin >> a;

    vector<int> v1(a);

    for (int i = 0; i < a; i++) {
        cin >> v1[i];
    }
    vector<int> v2 = v1;

    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    for (int i = 0; i < a; i++) {
        cout << lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin() << " ";
    }
}