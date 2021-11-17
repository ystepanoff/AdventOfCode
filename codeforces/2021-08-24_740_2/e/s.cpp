#include <bits/stdc++.h>
using namespace std;

int pos(vector<int> &a, int k) {
    for (int i = 1; i < a.size(); i++)
        if (a[i] == k)
            return i;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ok &= (a[i] & 1) == (i & 1);
        }
        if (ok) {
            vector<int> p;
            int x, y;
            for (int i = n; i > 1; i -= 2) {
                x = pos(a, i);
                p.push_back(x);
                reverse(a.begin() + 1, a.begin() + x + 1);
                y = pos(a, i - 1);
                p.push_back(y - 1);
                reverse(a.begin() + 1, a.begin() + y);
                p.push_back(y + 1);
                reverse(a.begin() + 1, a.begin() + y + 2);
                p.push_back(3);
                reverse(a.begin() + 1, a.begin() + 4);
                p.push_back(i);
                reverse(a.begin() + 1, a.begin() + i + 1);
            }
            cout << p.size() << '\n';
            for (int i = 0; i < p.size(); i++) {
                cout << p[i];
                if (i + 1 < p.size())
                    cout << ' ';
            }
            cout << '\n';
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}
