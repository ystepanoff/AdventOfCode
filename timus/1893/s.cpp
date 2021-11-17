#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    char seat = s.back();
    int row = stoi(s.substr(0, s.length() - 1));
    if (row <= 2) {
        if (seat == 'A' || seat == 'D') cout << "window";
        else cout << "aisle";
    } else if (row <= 20) {
        if (seat == 'A' || seat == 'F') cout << "window";
        else cout << "aisle";
    } else {
        // ABC DEFG HJK
        if (seat == 'A' || seat == 'K') cout << "window";
        else if (seat == 'C' || seat == 'D' || seat == 'G' || seat == 'H') cout << "aisle";
        else cout << "neither";
    }
    cout << '\n';
    return 0;
}
