#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int f;
    cin >> f;
    int c = 12 - f;
    cout << (c * 45 <= 4 * 60 ? "YES" : "NO") << "\n";
    return 0;
}
