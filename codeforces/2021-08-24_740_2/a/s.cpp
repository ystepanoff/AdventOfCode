#include <bits/stdc++.h>
using namespace std;

bool sorted(vector<int> &a) {
    for (int i = 1; i < a.size(); i++)
        if (a[i] < a[i - 1])
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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (sorted(a)) {
            cout << "0\n";
            continue;
        }
        for (int i = 1; ; i++) {
            for (int j = 1 - (i & 1); j < n - 1 + (i & 1); j += 2)
                if (j + 1 < n && a[j] > a[j + 1])
                    swap(a[j], a[j + 1]);
            if (sorted(a)) {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}
