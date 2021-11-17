#include <bits/stdc++.h>
using namespace std;

bool sorted(vector<int> &a) {
    for (int i = 1; i < a.size(); i++) {
        if (a[i] < a[i - 1]) return false;
    }
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        // [1, 3, 2, 4] -> [[1, 2, 3], 4]
        // [2, 1, 4, 5, 3] -> [[1, 2, 4, 5], 3] -> [1, 2, [3, 4, 5]]
        // sorted => 0
        // [n, *, ..., *, 1] -> [n, 1, *, ..., *] -> [1, n, *, ..., *] -> [1, *, ..., *, n] => 3
        // [*, n, ..., *, 1] -> [*, 1, *, ..., *, n] -> [1, *, ..., *, n] => 2
        // [1, *, ..., *, *] or [*, ..., *, n] => 1
        if (sorted(a)) {
            cout << "0\n";
        } else if (a[0] == n && a[n - 1] == 1) {
            cout << "3\n";
        } else if (a[0] == 1 || a[n - 1] == n) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
    return 0;
}
