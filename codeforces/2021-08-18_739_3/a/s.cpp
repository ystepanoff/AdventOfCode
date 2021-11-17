#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a(1);
    for (int i = 1; a.size() < 1010; i++)
        if (!(i % 3 == 0 || i % 10 == 3))
            a.push_back(i);
    int tt;
    cin >> tt;
    while (tt--) {
        int k;
        cin >> k;
        cout << a[k] << '\n';
    }
    return 0;
}
