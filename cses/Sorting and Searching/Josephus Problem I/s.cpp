#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    auto it = s.begin();
    if (++it == s.end()) it = s.begin();
    for (int i = 0; i < n - 1; i++) {
        cout << *it << ' ';
        auto it_next = it;
        if (++it_next == s.end()) it_next = s.begin();
        if (++it_next == s.end()) it_next = s.begin();
        s.erase(it);
        it = it_next;
    }
    for (int x : s)
        cout << x << ' ';
    cout << '\n';
    return 0;
}
