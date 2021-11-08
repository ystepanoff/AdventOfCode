#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        bool allz = true;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            allz &= a[i] == 0;
        }
        if (allz) {
            for (int i = 1; i <= n; i++) {
                cout << i << ' ';
            }
            cout << '\n';
            continue;
        }
        set<int> res;
        for (int j = 0; j < 31; j++) {
            int cnt = 0;
            for (int x : a) {
                if (x & (1 << j)) cnt++;
            }
            set<int> divs;
            for (int c = 1; c * c <= cnt; c++) {
                if (!(cnt % c)) {
                    divs.insert(c);
                    divs.insert(cnt / c);
                }
            }
            if (divs.size()) {
                if (res.size() == 0) {
                    res = divs;
                } else {
                    set<int> st;
                    set_intersection(res.begin(), res.end(), divs.begin(), divs.end(), inserter(st, st.begin()));
                    res = st;
                }
            }
        }
        for (int x : res) {
            cout << x << ' ';
        }
        cout << '\n';    
    }
    return 0;
}
