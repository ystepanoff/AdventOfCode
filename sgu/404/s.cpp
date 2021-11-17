#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << a[(n - 1) % m] << '\n';
    return 0;
}
