#include <bits/stdc++.h>
using namespace std;

struct city {
    int x, y, n;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<city> pts(n);
    for (int i = 0; i < n; i++) {
        city c;
        cin >> c.x >> c.y;
        c.n = i + 1;
        pts[i] = c;
    }
    sort(pts.begin(), pts.end(), [&](const city &a, const city &b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    for (int i = 0; i < n; i += 2)
        cout << pts[i].n << ' ' << pts[i + 1].n << '\n';
    return 0;
}
