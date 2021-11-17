#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    for (int i = 0; i < n + n; i++)
        for (int j = 0; j <= i; j++)
            if (j < n && i - j < n)
                cout << a[i - j][j] << ' ';
    cout << '\n';
    return 0;
}
