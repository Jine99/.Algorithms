#include<iostream>

using namespace std;

int arr[1000002];

long long N, M, total, Max, result, mid;

void binarySearch(int left, int right) {

    total = 0;
    mid = (left + right) / 2;
    if (left > right) {
        return;
    }
    for (int i = 0; i < N; i++) {
        if (arr[i] > mid) {
            total += arr[i] - mid;
        }
    }
    if (total >= M) {
        mid > result ? result = mid : result = result;
        binarySearch(mid + 1, right);
    }
    else {
        binarySearch(left, mid - 1);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr[i] > Max ? Max = arr[i] : Max = Max;
    }

    binarySearch(0, Max);

    cout << result;
}