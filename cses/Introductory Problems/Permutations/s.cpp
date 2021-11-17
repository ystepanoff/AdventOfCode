#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    for (int i = 1; i <= n; i++)
        if (!(i & 1))
            cout << i << ' ';
    for (int i = 1; i <= n; i++)
        if (i & 1)
            cout << i << ' ';
    cout << '\n';
    return 0;
}
