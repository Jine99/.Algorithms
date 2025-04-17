#include<iostream>
#include<string>

using namespace std;

int main() {

    string s;

    cin >> s;

    for (char i = 'a'; i <= 'z'; i++) {
        //find string::npos반환후 (int)형변환으로인해 overflow로 인한 -1 출력
        cout << (int)s.find(i) << " ";
    }

    // for (char i = 'a'; i <= 'z'; i++) {
    //     size_t pos = s.find(i);
    //     if (pos == string::npos)
    //         cout << -1 << " ";
    //     else
    //         cout << pos << " ";
    // }
}