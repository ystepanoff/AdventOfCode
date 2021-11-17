#include <bits/stdc++.h>
using namespace std;

long long merge(vector<int> &a, int l, int m, int r) {
    vector<int> b;
    long long t = 0;
    int i = l, j = m + 1;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) {
            b.push_back(a[i++]);
        } else {
            b.push_back(a[j++]);
            t += m - i + 1;
        }
    }
    while (i <= m)
        b.push_back(a[i++]);
    while (j <= r)
        b.push_back(a[j++]);
    for (int i = 0; i < b.size(); i++)
        a[i + l] = b[i];
    return t;
}

long long inv(vector<int> &a, int l, int r) {
    long long t = 0;
    if (r - l > 0) {
        int m = (l + r) >> 1;
        t += inv(a, l, m);
        t += inv(a, m + 1, r);
        t += merge(a, l, m, r);
    }
    return t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << inv(a, 0, n - 1) << '\n';
    return 0;
}
