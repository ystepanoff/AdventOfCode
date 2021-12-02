#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> a(5, vector<int> (5));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> p = { 0, 1, 2, 3, 4 };
    int best = 1e9;
    vector<int> bestp;
    do {
        if (p[0] != 0 || p[4] != 4 || p[3] == 2) continue;
        int curr = 0;
        for (int i = 1; i < 5; i++) {
            curr += a[p[i - 1]][p[i]];
        }
        if (curr < best) {
            best = curr;
            bestp = p;
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << best << '\n';
    for (int x : bestp) cout << x + 1 << ' ';
    cout << '\n';
    return 0;
}
