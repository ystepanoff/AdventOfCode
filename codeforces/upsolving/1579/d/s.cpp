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
        set<pair<int,int>> s;
        vector<pair<int,int>> r;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            s.insert({-v, i + 1});
        }
        while (1) {
            auto a = *s.begin();
            s.erase(a);
            auto b = *s.begin();
            s.erase(b);
            if (a.first < 0 && b.first < 0) {
                r.emplace_back(a.second, b.second);
                a.first++;
                b.first++;
                s.insert(a);
                s.insert(b);
            } else {
                break;
            }
        }
        cout << r.size() << '\n';
        for (auto p : r) {
            cout << p.first << ' ' << p.second << '\n';
        }
    }
    return 0;
}
