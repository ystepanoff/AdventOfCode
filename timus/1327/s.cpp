#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    cout << ((b - a + 1) >> 1) + (a & 1) * ((b - a + 1) & 1) << '\n';
    return 0;
}
