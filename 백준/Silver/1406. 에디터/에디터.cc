#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
char dat[MX];
int pre[MX];
int nxt[MX];
int unused = 1;

void insert(int addr, char c) {
    dat[unused] = c;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr] != -1)
        pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr) {
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1)
        pre[nxt[addr]] = pre[addr];
}

void traverse() {
    int a = nxt[0];
    while (a != -1) {
        cout << dat[a];
        a = nxt[a];
    }
}

int main(void) {
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);
    int cursor = 0;
    string init;
    cin >> init;
    for (char i : init) {
        insert(cursor, i);
        cursor++;
    }
    int a;
    cin >> a;
    while (a--) {
        char it;
        cin >> it;

        if (it == 'P') {
            char aa;
            cin >> aa;
            insert(cursor, aa);
            cursor = nxt[cursor];
        }
        else if (it == 'L') {
            if (pre[cursor] != -1)
                cursor = pre[cursor];
        }

        else if (it == 'D') {
            if (nxt[cursor] != -1)
                cursor = nxt[cursor];

        }
        else if (it == 'B' && pre[cursor] != -1) {
            erase(cursor);
            cursor = pre[cursor];
        }
    }
    traverse();
}