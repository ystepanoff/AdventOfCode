#include <bits/stdc++.h>
using namespace std;

bool equal(vector<int> &a, vector<int> &b) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i]) 
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        int sa = 0, sb = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sa += a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            sb += b[i];
        }
        if (sa != sb) {
            cout << "-1\n";
            continue;
        }
        vector<pair<int,int>> ops;
        while (!equal(a, b)) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (a[i] > b[i] && a[j] < b[j]) {
                        ops.emplace_back(i + 1, j + 1);
                        a[i]--;
                        a[j]++;
                    }
        }
        cout << ops.size() << '\n';
        for (auto p : ops)
            cout << p.first << ' ' << p.second << '\n'; 
    }
    return 0;
}
