#include <bits/stdc++.h>
using namespace std;

struct item {
    int l, r, d;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<item> b;
        for (int i = 0; i < n; i++) {
            int mi = min_element(a.begin() + i, a.end()) - a.begin();
            if (mi > i) {
                b.push_back({i + 1, mi + 1, mi - i});
                for (int j = 0; j < mi - i; j++) {
                    int x = a[i];
                    for (int k = i; k < mi; k++) {
                        a[k] = a[k + 1];
                    }
                    a[mi] = x;
                }
            }
        }
        cout << b.size() << '\n';
        for (auto x : b) {
            cout << x.l << ' ' << x.r << ' ' << x.d << '\n';
        }
    }
    return 0;
}
