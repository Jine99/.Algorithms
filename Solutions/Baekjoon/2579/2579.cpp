#include<iostream>
#include<algorithm>

using namespace std;

int stair[301];
int score[301];
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int count;
    cin >> count;

    for (int i = 1; i <= count;i++) {
        cin >> stair[i];
    }

    score[1] = stair[1];
    score[2] = score[1] + stair[2];
    score[3] = stair[3] + max(stair[1], stair[2]);

    for (int i = 4; i <= count; i++) {
        score[i] = stair[i] + max(stair[i - 1] + score[i - 3], score[i - 2]);
    }

    cout << score[count];
}