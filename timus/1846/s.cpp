#include <bits/stdc++.h>
using namespace std;

vector<int> t;

void update(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
        t[x] = v;
        return;
    }
    int m = (lx + rx) >> 1;
    if (i < m)
        update(i, v, (x << 1) + 1, lx, m);
    else
        update(i, v, (x << 1) + 2, m, rx);
    t[x] = __gcd(t[(x << 1) + 1], t[(x << 1) + 2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q; 
    cin >> q;
    t.assign(q << 2, 0);
    map<int,vector<int>> pos;
    for (int i = 0; i < q; i++) {
        char c;
        int v;
        cin >> c >> v;
        if (c == '+') {
            update(i, v, 0, 0, q);
            pos[v].push_back(i);
        } else {
            update(pos[v].back(), 0, 0, 0, q);
            pos[v].pop_back();
        }
        cout << (t[0] ? t[0] : 1) << '\n';
    }
    return 0;
}
