#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a(3);
    for (auto& x : a)
        cin >> x;
    cout << min(a[0] - a[1] * a[2], a[0] - a[1] - a[2]) << '\n';
    return 0;
}
