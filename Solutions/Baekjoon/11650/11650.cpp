#include<iostream>
#include<algorithm>

using namespace std;

pair<int, int> arr[100000];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr + a);

    for (int i = 0; i < a; i++) {
        cout << arr[i].first << " " << arr[i].second << "\n";
    }

}