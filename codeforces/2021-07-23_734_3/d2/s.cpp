#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<char>> b(max(n, m), vector<char>(max(n, m)));
        if (!(n & 1) && !(m & 1)) {
            if (!(k & 1)) {
                cout << "YES\n";
                for (int i = 0; i < n / 2; i++)
                    for (int j = 0; j < m / 2; j++) {
                        int ii = 2 * i, jj = 2 * j;
                        char c1 = 'a', c2 = 'b';
                        if ((i + j) & 1)
                            c1 = 'c', c2 = 'd';
                        if (k) {
                            b[ii][jj] = b[ii][jj + 1] = c1;
                            b[ii + 1][jj] = b[ii + 1][jj + 1] = c2;
                            k -= 2;
                        } else {
                            b[ii][jj] = b[ii + 1][jj] = c1;
                            b[ii][jj + 1] = b[ii + 1][jj + 1] = c2;
                        }
                    }
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++)
                        cout << b[i][j];
                    cout << '\n';
                }
            } else {
                cout << "NO\n";
            }
        } else {
            bool s = false;
            if (m & 1) {
                swap(n, m);
                k = (n * m) / 2 - k;
                s = true;
            }
            if (k >= m / 2 && !((k - m / 2) & 1)) {
                cout << "YES\n";
                char c = 'p';
                for (int i = 0; i < m; i += 2) {
                    b[0][i] = b[0][i + 1] = c;
                    c = c == 'p' ? 'q' : 'p';
                }
                k -= m / 2;
                for (int i = 0; i < n / 2; i++)
                    for (int j = 0; j < m / 2; j++) {
                        int ii = 2 * i + 1, jj = 2 * j;
                        char c1 = 'a', c2 = 'b';
                        if ((i + j) & 1)
                            c1 = 'c', c2 = 'd';
                        if (k) {
                            b[ii][jj] = b[ii][jj + 1] = c1;
                            b[ii + 1][jj] = b[ii + 1][jj + 1] = c2;
                            k -= 2;
                        } else {
                            b[ii][jj] = b[ii + 1][jj] = c1;
                            b[ii][jj + 1] = b[ii + 1][jj + 1] = c2;
                        }
                    }
                if (s)
                    swap(n, m);
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++)
                        cout << (s ? b[j][i] : b[i][j]);
                    cout << '\n';
                }
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
