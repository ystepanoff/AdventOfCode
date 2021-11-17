#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long curr = 0, total = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
        curr += a[r];
        while (curr > x)
            curr -= a[l++];
        if (curr == x) total++;
    }
    cout << total << '\n';
    return 0;
}
