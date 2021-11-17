#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<long long> mod(n, 0);
    long long s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
        long long t = s;
        if (t < 0) {
            t += (abs(t) / n + 1) * n;
        }
        mod[t % n]++;
    }
    long long total = mod[0];
    for (int i = 0; i < n; i++)
        if (mod[i] > 1)
            total += mod[i] * (mod[i] - 1) / 2;
    cout << total << '\n';
    return 0;
}
