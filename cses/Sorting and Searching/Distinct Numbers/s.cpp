#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> s;
    int total = 0;
    while (n--) {
        int v;
        cin >> v;
        if (s.find(v) == s.end()) {
            s.insert(v);
            total++;
        }
    }
    cout << total << '\n';
    return 0;
}
