#include <bits/stdc++.h>
using namespace std;

int main() {
    int state = 0;
    char c;
    while (cin.get(c)) {
        if (!((c >= 'a' && c <= 'z') ||
              (c >= 'A' && c <= 'Z') ||
              c == '.' ||
              c == '!' ||
              c == '?')) {
            cout << c;
            continue;
        }
        if (state == 0) {
            if (c >= 'a' && c <= 'z') {
                cout << (char)(c - 'a' + 'A');
                state = 1;
            } else {
                cout << c;
            }
            if (!(c == '.' || c == '!' || c == '?')) {
                state = 1;
            }
        } else {
            if (c >= 'A' && c <= 'Z') {
                cout << (char)(c - 'A' + 'a');
            } else {
                cout << c;
            }
            if (c == '.' || c == '!' || c == '?') {
                state = 0;
            }
        }
    }
    return 0;
}
