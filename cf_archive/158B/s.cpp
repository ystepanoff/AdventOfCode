#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        vector<int> a(5, 0);
        while (n--) {
            int v;
            cin >> v;
            a[v]++;
        }
        int res = a[4];
        res += a[3];
        a[1] = max(0, a[1] - a[3]);
        res += a[2] >> 1;
        if (a[2] & 1) {
            res++;
            a[1] = max(0, a[1] - 2);
        }
        res += (a[1] + 3) / 4;
        cout << res << '\n';
    }
    return 0;
}

