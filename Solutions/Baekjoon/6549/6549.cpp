#include<iostream>
#include<stack>

using namespace std;

stack<pair<long, long>> stk;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        long long inputsize;
        cin >> inputsize;
        if (inputsize == 0)break;

        long long size = 0;

        for (long long i = 0; i < inputsize; i++) {
            long long input;
            cin >> input;
            if (size < input) { size = input; }

            if (stk.empty()) {
                stk.push({ input,i });
                continue;
            }
            else if (stk.top().first == input) {
                continue;
            }
            else if (stk.top().first > input) {
                long long seat;
                while (!stk.empty() && stk.top().first > input) {

                    long long number = stk.top().first * (i - stk.top().second);

                    if (size < number) { size = number; }
                    seat = stk.top().second;
                    stk.pop();
                }
                stk.push({ input,seat });
            }
            else if (stk.top().first < input) {
                stk.push({ input,i });
                continue;
            }
        }
        while (!stk.empty()) {
            long long number = stk.top().first * (inputsize - stk.top().second);

            if (size < number) { size = number; }

            stk.pop();
        }
        cout << size << "\n";
    }
}