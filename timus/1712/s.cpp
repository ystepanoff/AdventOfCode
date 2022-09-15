#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<string> a(4), b(4);
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> b[i];
    }
    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (a[i][j] == 'X') cout << b[i][j];
            }
        }
        vector<string> c(4, "....");
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                c[j][3 - i] = a[i][j];
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                a[i][j] = c[i][j];
            }
        }
    }
    cout << '\n';
    return 0;
}
