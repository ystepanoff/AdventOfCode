#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        if (!a[n]) {
            for (int i = 1; i <= n + 1; i++)
                cout << i << ' ';
            cout << '\n';
        } else {
            int k = -1;
            for (int i = 1; i <= n - 1; i++)
                if (!a[i] && a[i + 1]) {
                    k = i;
                    break;
                }
            if (k > 0) {
                for (int i = 1; i <= k; i++)
                    cout << i << ' ';
                cout << n + 1 << ' ';
                for (int i = k + 1; i <= n; i++)
                    cout << i << ' ';
                cout << '\n';
            } else {
                if (a[1] == 1) {
                    cout << n + 1 << ' ';
                    for (int i = 1; i <= n; i++)
                        cout << i << ' ';
                    cout << '\n';
                } else {
                    cout << "-1\n";
                }
            }
        }
    }
    return 0;
}
