#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool comp(string s1, string s2) {
    if (s1.length() == s2.length()) {
        return s1 < s2;
    }
    else
        return s1.length() < s2.length();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int  a;
    cin >> a;

    vector<string> vec;

    for (int i = 0; i < a; i++) {
        string b;
        cin >> b;
        vec.push_back(b);
    }

    sort(vec.begin(), vec.end(), comp);
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << "\n";
    }
}