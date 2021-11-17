#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    int l = 1, r = n - (n & 1);
    vector<int> a, b;
    if (n & 1) b.push_back(n);
    while (l < r) {
        if (l <= r) {
            a.push_back(l++);
            a.push_back(r--);
        }
        if (l <= r) {
            b.push_back(l++);
            b.push_back(r--);
        }
    }
    cout << a.size() << '\n';
    for (int i : a) cout << i << ' ';
    cout << '\n';
    cout << b.size() << '\n';
    for (int i : b) cout << i << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if ((n % 4 == 0 || (n + 1) % 4 == 0)) {
        cout << "YES\n";
        solve(n);
    } else {
        cout << "NO\n";
    }
    return 0;
}
