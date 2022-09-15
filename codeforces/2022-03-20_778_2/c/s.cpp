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
        multiset<long long> st;
        for (int i = 0; i < n; i++) {
            long long v;
            cin >> v;
            st.insert(v);
            cout << v << ' ';
        }
        cout << '\n';
        bool yes = true;
        while (st.size() > 1) {
            auto a = *st.begin();
            st.erase(st.begin());
            auto b = *st.begin();
            st.erase(st.begin());
            if (b - a <= 1) {
                st.insert(a + b);
            } else {
                yes = false;
                break;
            }
        }
        cout << (yes ? "yes" : "no") << '\n';
    }
    return 0;
}

