#include <bits/stdc++.h>
using namespace std;

bool empty(vector<string> &a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            if (a[i][j] != '.') return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        int r, c;
        cin >> r >> c;
        vector<string> a(r);
        for (int i = 0; i < r; i++) {
            cin >> a[i];
        }
        cout << "Case #" << t << ": ";
        if (empty(a)) {
            cout << "Possible\n";
            for (int i = 0; i < r; i++) {
                cout << a[i] << '\n';
            }
        } else {
            if (r == 1 || c == 1) {
                cout << "Impossible\n";
            } else {
                cout << "Possible\n";
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        cout << '^';
                    }
                    cout << '\n';
                }
            }
        }
    }
    return 0;
}
