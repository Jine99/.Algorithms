#include<iostream>
#include<set>
#include<map>

using namespace std;

int arr[1000002];
set<int> S;
map<int, int> M;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b = 0;
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> arr[i];
        S.insert(arr[i]);
    }

    for (auto s : S) {
        M.insert({ s, M.size() });
    }

    for (int i = 0; i < a; i++) {
        cout << M[arr[i]] << " ";
    }
}