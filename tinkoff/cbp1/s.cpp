#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (k > 0) {
        k %= 4;
        if (!k) k = 4;
        while (k--) {
            vector<int> b(n, 0);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    b[i] += (int)(a[j] >= i + 1);
            }
            a = b;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i + 1 < n) cout << ' ';
    }
    cout << '\n';
    return 0;
}
