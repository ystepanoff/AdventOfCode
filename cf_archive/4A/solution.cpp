#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int w;
    cin >> w;
    if ((w & 1) || w == 2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    return 0;
}
