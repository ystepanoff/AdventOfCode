#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a(3), b(3);
    for (int i = 0; i < 3; i++)
        cin >> a[i] >> b[i];
    cout << a[0] - a[2] << ' ' << b[0] - b[1] << '\n';
    return 0;
}
