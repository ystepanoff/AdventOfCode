#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    multiset<int> s;
    int n; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        auto it = s.lower_bound(v + 1);
        if (it == s.end()) {
            s.insert(v);
        } else {
            s.erase(it);
            s.insert(v);
        }
    }
    cout << s.size() << '\n';
    return 0;
}
