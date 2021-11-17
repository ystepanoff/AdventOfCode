#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(7);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        long long s = accumulate(a.begin(), a.end() - 1, 0LL);
        cout << (s * 1.0) / (n - 1) + a.back() << '\n';
    }
    return 0;
}
