#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.rbegin(), a.rend());
        int s = 0, total = accumulate(a.begin(), a.end(), 0);
        for (int i = 0; i < n; i++) {
            s += a[i];
            if (s > total - s) {
                cout << i + 1 << '\n';
                break;
            }
        }
    }
    return 0;
}
