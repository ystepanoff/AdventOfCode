#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (n));
    int c = 1;
    for (int i = 0; i < n + n; i++)
        for (int j = i; j >= 0; j--)
            if (j < n && i - j < n)
                a[i - j][n - j - 1] = c++;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
