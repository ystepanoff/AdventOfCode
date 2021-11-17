#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while (cin >> s) {
        int n = s.length();
        int c = 0;
        for (char ch : s)
            if (ch >= 'a' && ch <= 'z')
                c++;
        for (char ch : s)
            if (c >= n - c)
                cout << (char)tolower(ch);
            else
                cout << (char)toupper(ch);
        cout << '\n';
    }
    return 0;
}
