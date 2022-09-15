#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    while (cin >> s) {
        int m = s.length();
        if (m == n) {
            int x = 0;
            for (int i = 0; i < m; i++)
                if (s[i] == '1') x += i + 1;
            if (x % (n + 1) != 0) {
                for (int i = 0; i < m; i++)
                    if (s[i] == '1' && (x - i - 1) % (n + 1) == 0) {
                        s[i] = '0';
                        break;
                    }
            }
            cout << s << '\n';
        } else {
            int totalx = 0, total = 0;
            for (int i = 0; i < m; i++)
                if (s[i] == '1') {
                    totalx += i + 1;
                    total++;
                }
            int x = 0, y = 0;
            int nx = 0, ny = 0;
            for (int i = 0; i < m; i++) {
                if (s[i] == '1') {
                    x += i + 1;
                    nx++;
                }
                y = totalx - x;
                ny = total - nx;
                if (m < n) {
                    if ((x + y + ny) % (n + 1) == 0) {
                        cout << s.substr(0, i + 1) << '0' << s.substr(i + 1) << '\n';
                        break;
                    } else if ((x + y + ny + i + 1) % (n + 1) == 0) {
                        cout << s.substr(0, i) << '1' << s.substr(i) << '\n';
                        break;
                    } else if (i == m - 1) {
                        cout << s << '1' << '\n';
                        break;
                    }
                } else {
                    if (s[i] == '0' && (x + y - ny) % (n + 1) == 0) {
                        cout << s.substr(0, i) << s.substr(i + 1) << '\n';
                        break;
                    } else if (s[i] == '1' && (x + y - ny - i - 1) % (n + 1) == 0) {
                        cout << s.substr(0, i) << s.substr(i + 1) << '\n';
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
