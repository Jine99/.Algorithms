#include<iostream>
#include<map>

using namespace std;

enum set
{
    Add,
    Remove,
    Check,
    Toggle,
    Empty,
    All
};

bool arr[21];

map<string, set> setmap
{ {"add",Add} ,{ "remove",Remove },{"check",Check},{"toggle",Toggle},{"all",All},{"empty",Empty} };

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0);

    string input;
    int a, b;
    cin >> a;

    while (a--) {
        cin >> input;

        switch (setmap[input]) {
        case Add:
            cin >> b;
            arr[b] = 1;
            break;
        case Remove:
            cin >> b;
            arr[b] = 0;
            break;
        case Check:
            cin >> b;
            arr[b] ? cout << "1\n" : cout << "0\n";
            break;
        case Toggle:
            cin >> b;
            arr[b] ? arr[b] = 0 : arr[b] = 1;
            break;
        case Empty:
            for (int i = 1; i < 21; i++) arr[i] = 0;
            break;
        case All:
            for (int i = 1; i < 21; i++) arr[i] = 1;
            break;

        }
    }
}