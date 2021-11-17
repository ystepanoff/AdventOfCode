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
    long long s = accumulate(a.begin(), a.end(), 0LL);
    long long t = *max_element(a.begin(), a.end());
    cout << max(s, 2 * t) << '\n';
    return 0;
}
