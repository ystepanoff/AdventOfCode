#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    long long s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
        s1 += abs(a[i] - a[n / 2]);
        s2 += abs(a[i] - a[1 + n / 2]);
    }
    cout << min(s1, s2) << '\n';
    return 0;
}
