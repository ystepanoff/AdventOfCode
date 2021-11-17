#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        bool done = false;
        for (int i = 1; i <= 8; i++) {
            if (i & 1) {
                if (!done) for (int j = 1; j <= 8; j++) {
                    cout << i << ' ' << j << '\n';
                    cout.flush();
                    string s;
                    cin >> s;
                    if (!s.compare("Done")) {
                        done = true;
                        break;
                    }
                }
            } else {
                if (!done) for (int j = 8; j >= 1; j--) {
                    cout << i << ' ' << j << '\n';
                    cout.flush();
                    string s;
                    cin >> s;
                    if (!s.compare("Done")) {
                        done = true;
                        break;
                    }
                }
            }
        }
        if (!done) {
            for (int i = 8; i >= 1; i--) {
                if (i & 1) {
                    if (!done) for (int j = 8; j >= 1; j--) {
                        cout << i << ' ' << j << '\n';
                        cout.flush();
                        string s;
                        cin >> s;
                        if (!s.compare("Done")) {
                            done = true;
                            break;
                        }
                    }
                } else {
                    if (!done) for (int j = (i == 8 ? 2 : 1); j <= 8; j++) {
                        cout << i << ' ' << j << '\n';
                        cout.flush();
                        string s;
                        cin >> s;
                        if (!s.compare("Done")) {
                            done = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
