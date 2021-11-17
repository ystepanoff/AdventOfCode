#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(3, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++) {
            int v;
            cin >> v;
            a[j] += v;
        }
    bool yes = true;
    for (int i = 0; i < 3; i++)
        yes &= a[i] == 0;
    cout << (yes ? "YES" : "NO") << '\n';
    return 0;
}
