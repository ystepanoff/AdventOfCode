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
        deque<int> d;
        while (n--) {
            int v;
            cin >> v;
            if (d.size() > 0 && v < *d.begin())
                d.push_front(v);
            else
                d.push_back(v);
        }
        for (int x : d)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
