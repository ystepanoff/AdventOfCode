#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a.push_back(m + 1);
    for (int i = n - 1; i >= 0; i--)
        a.push_back(a[i]);
    int k = a.size();
    vector<int> z(k, 0);
    for (int i = 1, l = 0, r = 0; i < k; i++) {
        if (r >= i)
            z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < k && a[i + z[i]] == a[z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    for (int i = n / 2; i >= 1; i--)
        if (z[k - 2 * i] >= i)
            cout << n - i << ' ';
    cout << n << '\n';
    return 0;
}
